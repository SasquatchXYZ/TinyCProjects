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

int count;

void find(char* dir_path, const char* parent_path, char* match)
{
    DIR* dir = opendir(dir_path);
    if (dir == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", dir_path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // Compare filename found with the passed filename
        if (strcmp(entry->d_name, match) == 0)
        {
            // Output matching file name
            printf("%s/%s\n", dir_path, match);
            // Increment the external `count` variable
            count++;
        }

        struct stat fs;
        stat(entry->d_name, &fs);
        if (S_ISDIR(fs.st_mode))
        {
            // Avoid checking the hidden files
            if (strncmp(entry->d_name, ".", 1) == 0)
                continue;
            if (chdir(entry->d_name) == -1)
            {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }

            char subdirectory_path[PATH_MAX];
            getcwd(subdirectory_path, BUFSIZ);
            find(subdirectory_path, dir_path, match); // Recursive call
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

int main(const int argc, const char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Format: ff filename\n");
        exit(1);
    }

    const char current[PATH_MAX];
    getcwd(current, PATH_MAX);

    if (chdir(current) == -1)
    {
        fprintf(stderr, "Unable to access directory %s\n", current);
        exit(1);
    }

    // Initializes the external `count` variable which keeps track
    // of the files found
    count = 0;
    printf("Searching for '%s'\n", argv[1]);
    find(current, NULL, argv[1]);
    printf(" Found %d match", count);
    if (count != 1)
        printf("es");
    putchar('\n');

    return 0;
}
