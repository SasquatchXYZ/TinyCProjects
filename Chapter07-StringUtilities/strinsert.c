#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strinsert(const char* original_string, char* insert_string, int offset)
{
    if (offset < 0) return NULL;

    // Calculate the size for the new string
    const int size = strlen(original_string) + strlen(insert_string);

    // Allocates storage for the new string
    char* new_string = malloc(sizeof(char) * size + 1);
    if (new_string == NULL)
    {
        fprintf(stderr, "Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    // Decrement the offset since strings start at 0
    offset -= 1;
    int index = 0;
    int append = 0;

    // Loop through the original string
    while (*original_string)
    {
        if (index == offset)
        {
            // Add the insert string to the new string
            while (*insert_string)
            {
                *(new_string + index) = *insert_string;
                index++;
                insert_string++;
            }
            // Mark that the insert has completed
            append = 1;
        }
        // Continue building the new string from the original
        *(new_string + index) = *original_string;
        index++;
        original_string++;
    }

    // Confirm that a string ws inserted, if not `insert_string` is appended
    if (!append)
    {
        while (*insert_string)
        {
            *(new_string + index) = *insert_string;
            index++;
            insert_string++;
        }
    }
    // Add null terminator
    *(new_string + index) = '\0';

    return new_string;
}

int main()
{
    const char s1[] = "Well, this is another mess!";
    const char s2[] = "fine ";

    char* s3 = strinsert(s1, s2, 23);

    printf("Before: %s\n", s1);
    printf("After: %s\n", s3);

    free(s3);

    return 0;
}
