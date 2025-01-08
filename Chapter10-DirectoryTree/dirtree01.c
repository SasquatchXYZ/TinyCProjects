#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

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

void dir(const char* dir_path, const char* parent_path)
{
    DIR* dp = opendir(dir_path);
    if (dp == NULL)
    {
        fprintf(stderr, "Unable to read directory '%s'\n", dir_path);
        exit(1);
    }

    printf("%s\n", extract(dir_path));

    struct dirent* entry;
    while ((entry = readdir(dp)) != NULL)
    {
        struct stat fs;

        if (strncmp(entry->d_name, ".", 1) == 0)
            continue;

        stat(entry->d_name, &fs);

        if (S_ISDIR(fs.st_mode))
        {
            if (chdir(entry->d_name) == -1)
            {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }

            char sub_dir_path[BUFSIZ];
            getcwd(sub_dir_path, BUFSIZ);
            dir(sub_dir_path, dir_path);
        }
    }

    closedir(dp);

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
    char current_path[BUFSIZ];

    if (argc < 2)
    {
        getcwd(current_path, BUFSIZ);
    }
    else
    {
        strcpy(current_path, argv[1]);
        if (chdir(current_path) == -1)
        {
            fprintf(stderr, "Unable to access directory %s\n", current_path);
            exit(1);
        }
        getcwd(current_path, BUFSIZ);
    }

    dir(current_path, NULL);

    return 0;
}
