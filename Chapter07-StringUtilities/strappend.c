#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strappend(const char* dest, const char* src)
{
    // Allocate storage for the new string
    // Note: we cannot use `sizeof` here since we have pointers, so it would return
    // the size of the pointer, not the string's storage
    // Destination length + source length + 1 for the '\0'
    char* result = malloc(strlen(dest) + strlen(src) + 1);

    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    char* index = result;

    // Copy the first string
    while (*dest)
    {
        *index = *dest;
        index++;
        dest++;
    }

    // Copy the second string
    while (*src)
    {
        *index = *src;
        index++;
        src++;
    }

    // Terminate the string
    *index = '\0';

    return result;
}

int main()
{
    char s1[] = "This is another ";
    char s2[] = "fine mess!";

    char* s3 = strappend(s1, s2);
    printf("%s\n", s3);

    free(s3);

    return 0;
}
