#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void dir(const char* dir_path, const char* parent_path)
{
    // The program is already in the desired directory, so rather than
    // changing to it, the code attempts to open the directory
    // and read the entries
    DIR* dp = opendir(dir_path);
    if (dp == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", dir_path);
        exit(1);
    }

    // Outputs the current directory path
    printf("%s\n", dir_path);

    struct dirent* entry;
    // Reads all entries in the directory
    while ((entry = readdir(dp)) != NULL)
    {
        struct stat fs;

        // Avoids any dot entries
        if (strncmp(entry->d_name, ".", 1) == 0)
            continue;

        // Gets info for each directory entry (inode)
        stat(entry->d_name, &fs);

        // Checks for subdirectory entry
        if (S_ISDIR(fs.st_mode))
        {
            // Changes to the subdirectory
            if (chdir(entry->d_name) == -1)
            {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }

            char sub_dir_path[BUFSIZ];
            // Gets the subdirectory's full pathname for the recursive call
            getcwd(sub_dir_path, BUFSIZ);
            // Recursively calls the function with the subdirectory and current directory
            // as arguments
            dir(sub_dir_path, dir_path);
        }
    }

    closedir(dp);

    // Changes back to the parent directory - full pathname
    if (chdir(parent_path) == -1)
    {
        // Checks for NULL, in which case, just returns
        if (parent_path == NULL)
            return;

        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main(const int argc, const char* argv[])
{
    char current_path[BUFSIZ];

    if (argc < 2)
    {
        // For no arguments, obtains and stores the full path to the current directory
        getcwd(current_path, BUFSIZ);
    }
    else
    {
        // Takes the first argument, hopefully a directory
        strcpy(current_path, argv[1]);
        // Changes to the directory and checks for errors
        if (chdir(current_path) == -1)
        {
            fprintf(stderr, "Unable to access directory %s\n", current_path);
            exit(1);
        }
        // Gets the directory's full pathname
        getcwd(current_path, BUFSIZ);
    }

    // Calls the recursive function; NULL is checked in the function
    dir(current_path, NULL);

    return 0;
}
