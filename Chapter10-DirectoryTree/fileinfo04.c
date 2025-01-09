#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(const int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Specify a filename\n");
        exit(1);
    }

    char* filename = argv[1];
    printf("Information for file '%s'\n", filename);
    struct stat fs;
    const int r = stat(filename, &fs);

    if (r == -1)
    {
        fprintf(stderr, "Error reading '%s'\n", filename);
        exit(1);
    }

    printf("File '%s' is a ", filename);

    if (S_ISBLK(fs.st_mode))
        printf("Block special\n");
    else if (S_ISCHR(fs.st_mode))
        printf("Character special\n");
    else if (S_ISDIR(fs.st_mode))
        printf("Directory\n");
    else if (S_ISFIFO(fs.st_mode))
        printf("Named pipe or socket\n");
    else if (S_ISREG(fs.st_mode))
        printf("Regular file\n");
    else if (S_ISLNK(fs.st_mode))
        printf("Symbolic link\n");
    else if (S_ISSOCK(fs.st_mode))
        printf("Socket\n");
    else
        printf("Type Unknown\n");

    printf("Owner permissions: ");
    if (fs.st_mode & S_IRUSR)
        printf("read");
    if (fs.st_mode & S_IWUSR)
        printf("write");
    if (fs.st_mode & S_IXUSR)
        printf("execute");
    putchar('\n');

    printf("Group permissions: ");
    if (fs.st_mode & S_IRGRP)
        printf("read");
    if (fs.st_mode & S_IWGRP)
        printf("write");
    if (fs.st_mode & S_IXGRP)
        printf("execute");
    putchar('\n');

    printf("Other permissions: ");
    if (fs.st_mode & S_IROTH)
        printf("read");
    if (fs.st_mode & S_IWOTH)
        printf("write");
    if (fs.st_mode & S_IXOTH)
        printf("execute");

    putchar('\n');

    return 0;
}
