#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void permissions_out(const mode_t mode)
{
    putchar(mode & S_IRUSR ? 'r' : '-');
    putchar(mode & S_IWUSR ? 'w' : '-');
    putchar(mode & S_IXUSR ? 'x' : '-');
    putchar(mode & S_IRGRP ? 'r' : '-');
    putchar(mode & S_IWGRP ? 'w' : '-');
    putchar(mode & S_IXGRP ? 'x' : '-');
    putchar(mode & S_IROTH ? 'r' : '-');
    putchar(mode & S_IWOTH ? 'w' : '-');
    putchar(mode & S_IXOTH ? 'x' : '-');
    putchar('\n');
}

int main(const int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Specify a filename\n");
        exit(1);
    }

    char* filename = argv[1];
    struct stat fs;
    const int r = stat(filename, &fs);

    if (r == -1)
    {
        fprintf(stderr, "Error reading '%s'\n", filename);
        exit(1);
    }

    printf("Permissions for file %s: ", filename);
    permissions_out(fs.st_mode);

    return 0;
}
