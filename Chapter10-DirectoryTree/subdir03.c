#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(const int argc, const char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Missing directory name\n");
        exit(1);
    }

    const char* dirname = argv[1];

    int r = chdir(dirname);
    if (r == -1)
    {
        fprintf(stderr, "Unable to change to %s\n", dirname);
        exit(1);
    }

    DIR* dp = opendir(dirname);
    if (dp == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", dirname);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dp)) != NULL)
    {
        struct stat fs;
        const char* filename = entry->d_name;

        if (strncmp(filename, ".", 1) == 0)
            continue;

        r = stat(filename, &fs);
        if (r == -1)
        {
            fprintf(stderr, "Error on '%s'\n", filename);
            exit(1);
        }

        if (S_ISDIR(fs.st_mode))
            printf("Found directory: %s\n", filename);
    }

    closedir(dp);

    return 0;
}
