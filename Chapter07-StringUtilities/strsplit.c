#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsplit(const char* input_string, const int offset, char** side1, char** side2)
{
    const int length = strlen(input_string);

    if (offset > length) return EXIT_SUCCESS;

    *side1 = malloc(sizeof(char) * (offset + 1));
    *side2 = malloc(sizeof(char) * (length - offset + 1));

    if (*side1 == NULL || *side2 == NULL) return EXIT_FAILURE;

    strncpy(*side1, input_string, offset);
    strncpy(*side2, input_string + offset, length - offset);

    return EXIT_SUCCESS;
}

int main()
{
    const char string[] = "When this baby hits 88 miles per hour.";

    char *first, *second;

    const int r = strsplit(string, 15, &first, &second);
    if (r == EXIT_SUCCESS)
    {
        printf("Split successful\n");
        printf("'%s' split into:\n", string);
        printf("First: '%s'\n", first);
        printf("Second: '%s'\n", second);
    }
    else
    {
        puts("Unable to split string.");
    }

    return 0;
}
