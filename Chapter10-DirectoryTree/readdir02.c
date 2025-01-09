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

    // The `dirent` struct is created as a pointer, a memory address
    // The entry is read and stored in the `dirent` structure `entry`
    struct dirent* entry = readdir(dp);

    // Output the `d_name` member
    printf("File %s\n", entry->d_name);

    closedir(dp);

    return 0;
}
