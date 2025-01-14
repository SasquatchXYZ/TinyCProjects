#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR* dp = opendir(".");

    if (dp == NULL)
    {
        puts("Unable to read directory");
        exit(1);
    }

    struct dirent* entry;

    while ((entry = readdir(dp)) != NULL)
    {
        printf("File %s\n", entry->d_name);
    }

    closedir(dp);

    return 0;
}
