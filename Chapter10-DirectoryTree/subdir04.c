#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void dir(const char* dirname)
{
    // Confirms the program ccn change to the name directory
    if (chdir(dirname) == -1)
    {
        fprintf(stderr, "Unable to change to %s\n", dirname);
        exit(1);
    }

    char directory[BUFSIZ];
    // Gets the current working directory/full pathname
    getcwd(directory, BUFSIZ);

    // Confirms that the directory can be opened
    DIR* dp = opendir(directory);
    if (dp == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", directory);
        exit(1);
    }

    // Outputs the directory name
    printf("%s\n", directory);

    struct dirent* entry;
    // Loops through the directory's entries looking for subdirectories
    while ((entry = readdir(dp)) != NULL)
    {
        struct stat fs;
        // Saves the filename for readability
        const char* filename = entry->d_name;

        // Ignores the dot and dot-dot entries as well as hidden files
        if (strncmp(filename, ".", 1) == 0)
            continue;

        // Gets the details of the found directory entry (inode)
        stat(filename, &fs);

        // Checks for a subdirectory...
        if (S_ISDIR(fs.st_mode))
            dir(filename); // ... if so recursively searches through it
    }

    closedir(dp);
}

int main(const int argc, const char* argv[])
{
    if (argc < 2)
    {
        dir(".");
    }
    else
    {
        dir(argv[1]);
    }

    return 0;
}
