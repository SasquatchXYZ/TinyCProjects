#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

struct file_info
{
    int index; // Keeps a count of the files found
    char name[BUFSIZ]; // File name
    char path[PATH_MAX]; // File path
    struct file_info* next; // Reference to the next node in the linked list, or NULL for the end of the list
};

void find(char* dir_path, const char* parent_path, struct file_info* file_info)
{
    DIR* dir = opendir(dir_path);
    if (dir == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", dir_path);
        exit(1);
        /* Will free memory as it exits */
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL)
    {
        struct stat fs;
        stat(entry->d_name, &fs);
        // Tests for a subdirectory and recursion
        if (S_ISDIR(fs.st_mode))
        {
            if (strncmp(entry->d_name, ".", 1) == 0)
                continue;

            if (chdir(entry->d_name) == -1)
            {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }

            char subdirectory_path[PATH_MAX];
            getcwd(subdirectory_path, BUFSIZ);
            find(subdirectory_path, dir_path, file_info);
        }
        // If not a subdirectory, save the file information
        else
        {
            file_info->next = malloc(sizeof(struct file_info) * 1);
            if (file_info->next == NULL)
            {
                fprintf(stderr, "Unable to allocate memory for new structure\n");
                exit(1);
            }

            // Save the current index value
            const int index = file_info->index;
            // References the newly created node
            file_info = file_info->next;
            // Update the index value
            file_info->index = index + 1;
            // Save the file name and path
            strcpy(file_info->name, entry->d_name);
            strcpy(file_info->path, dir_path);
            // Initializes the next pointer
            file_info->next = NULL;
        }
    }

    closedir(dir);

    if (chdir(parent_path) == -1)
    {
        if (parent_path == NULL)
            return;
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main()
{
    struct file_info* first = malloc(sizeof(struct file_info) * 1);
    if (first == NULL)
    {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    first->index = 0;
    strcpy(first->name, "");
    strcpy(first->path, "");
    first->next = NULL;

    char start_directory[PATH_MAX];
    getcwd(start_directory, PATH_MAX);
    if (chdir(start_directory) == -1)
    {
        fprintf(stderr, "Unable to access directory %s\n", start_directory);
        exit(1);
    }

    find(start_directory, NULL, first);

    struct file_info* current = first;
    // Loop as long as the `current` pointer isn't NULL
    while (current)
    {
        // Skips over the first item in the list, zero
        if (current->index > 0)
            printf("%d:%s/%s\n", current->index, current->path, current->name);

        current = current->next;
    }

    return 0;
}
