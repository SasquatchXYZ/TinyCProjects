#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct dir_entry
{
    char* name;
    char path[BUFSIZ];
    char parent[BUFSIZ];
    int depth;
    int last;
};

const char* extract(const char* path)
{
    const int len = strlen(path);

    if (len == 0)
        return NULL;

    if (len == 1 & *(path + 0) == '/')
        return path;

    const char* p = path + len;

    while (*p != '/')
    {
        p--;
        if (p == path)
            return NULL;
    }

    p++;

    if (*p == '\0')
        return NULL;

    return p;
}

void dir(struct dir_entry* dir_entry, const int i)
{
    (dir_entry + i)->last = FALSE;

    DIR* dp = opendir((dir_entry + i)->path);
    if (dp == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", (dir_entry + i)->path);
        exit(1);
    }

    for (int indent = 0; indent < (dir_entry + i)->depth; indent++)
    {
        if (indent == (dir_entry + i)->depth - 1)
            printf("+--");
        else
            printf("|  ");
    }

    (dir_entry + i)->name = extract((dir_entry + i)->path);
    printf("%s\n", (dir_entry + i)->name);

    struct dirent* entry;
    while ((entry = readdir(dp)) != NULL)
    {
        if (strncmp(entry->d_name, ".", 1) == 0)
            continue;

        struct stat fs;
        stat(entry->d_name, &fs);

        if (S_ISDIR(fs.st_mode))
        {
            if (chdir(entry->d_name) == -1)
            {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }

            getcwd((dir_entry + i + 1)->path, BUFSIZ);
            strcpy((dir_entry + i + 1)->parent, (dir_entry + i)->path);
            (dir_entry + i + 1)->depth = (dir_entry + i)->depth + 1;
            dir(dir_entry, i + 1);
        }
    }

    closedir(dp);

    (dir_entry + i)->last = TRUE;
    if (chdir((dir_entry + i)->parent) == -1)
        return;
}

int main(const int argc, const char* argv[])
{
    struct dir_entry* dir_entry = malloc(sizeof(struct dir_entry) * 100);
    if (dir_entry == NULL)
    {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    int i = 0;
    if (argc < 2)
    {
        getcwd((dir_entry + i)->path, BUFSIZ);
    }
    else
    {
        strcpy((dir_entry + i)->path, argv[1]);
        if (chdir((dir_entry + i)->path) == -1)
        {
            fprintf(stderr, "Unable to access directory %s\n", (dir_entry + i)->path);
            exit(1);
        }
        getcwd((dir_entry + i)->path, BUFSIZ);
    }

    dir(dir_entry + i, 0);

    return 0;
}
