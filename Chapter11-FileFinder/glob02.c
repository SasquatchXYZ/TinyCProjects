#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

int main()
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

    // Structure specified in the `glob()` function
    glob_t gstruct;
    int g = glob(filename, GLOB_ERR, NULL, &gstruct);
    if (g != 0)
    {
        if (g == GLOB_NOMATCH)
            fprintf(stderr, "No matches for '%s'\n", filename);
        else
            fprintf(stderr, "Glob Error\n");

        exit(1);
    }

    // Output the matches using the structure member `gl_pathc`
    // placeholder `%zu` is used for the `size_t` value
    printf("Found %zu filename matches\n", gstruct.gl_pathc);
    // Double pointer for the list of matching filenames
    // `gl_pathv` member is the base pointer list
    char** found = gstruct.gl_pathv;

    while (*found)
    {
        printf("%s\n", *found);
        found++;
    }

    return 0;
}
