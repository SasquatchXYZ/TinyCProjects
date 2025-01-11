#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <glob.h>

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

    glob_t gstruct;
    // Uses `glob()` to find matching files in the directory
    const int g = glob(match, GLOB_ERR, NULL, &gstruct);
    // On success, outputs the found files (here instead of below)
    if (g == 0)
    {
        char** found = gstruct.gl_pathv;
        while (*found)
        {
            printf("%s/%s\n", dir_path, *found);
            found++;
            count++;
        }
    }

    struct dirent* entry;
    // We still need this loop to find and explore subdirectories
    while ((entry = readdir(dir)) != NULL)
    {
        struct stat fs;
        stat(entry->d_name, &fs);
        // Just look for directories here, matching files already output
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
            find(subdirectory_path, dir_path, match);
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
    char filename[PATH_MAX];

    printf("Filename or wildcard: ");
    char* user_input = fgets(filename, PATH_MAX, stdin);
    if (user_input == NULL)
        exit(1);

    while (*user_input != '\0')
    {
        if (*user_input == '\n')
        {
            *user_input = '\0';
            break;
        }
        user_input++;
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
    printf("Searching for '%s'\n", filename);
    find(current, NULL, filename);
    printf(" Found %d match", count);
    if (count != 1)
        printf("es");
    putchar('\n');

    return 0;
}
