#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char* strrev(const char* s)
{
    // Contains the offset of the null character and also the string's length
    int length = 0;
    // Loops until `*s` references the null character terminating the string
    while (*s)
    {
        length++;
        s++;
    }

    // Allocate memory for the reversed string - the same length as the passed string
    char* reversed = malloc(sizeof(char) * length);
    if (reversed == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for reversed string.\n");
        exit(EXIT_FAILURE);
    }

    // Back up `s` so it now points the last character in the past string, before the terminating character
    s--;
    int i = 0;
    // Copy the string backwards
    while (length)
    {
        *(reversed + i) = *s;
        i++; // Increment the offset for the reversed string
        length--; // Decrement the offset for the original string
        s--; // Back up the pointer
    }
    // Terminate the reversed string
    *(reversed + i) = '\0';

    return reversed;
}

int main()
{
    const char string[] = "this is a sample string.";

    printf("Original string: %s\n", string);

    char* reversed = strrev(string);
    printf("Reversed string: %s\n", reversed);

    free(reversed);

    return 0;
}
