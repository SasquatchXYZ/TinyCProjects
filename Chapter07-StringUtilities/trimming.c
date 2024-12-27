#include <stdio.h>
#include <stdlib.h>

char* left(const char* input_string, const int length)
{
    char* outputBuffer = malloc(sizeof(char) * length + 1);

    if (outputBuffer == NULL)
    {
        fprintf(stderr, "Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    int i;
    // Copy the first `length` characters of `string` to `buffer`
    for (i = 0; i < length; i++)
    {
        // Terminate the loop if an unexpected null character is found
        if (*(input_string + i) == '\0') break;
        *(outputBuffer + i) = *(input_string + i);
    }

    // Cap the string
    *(outputBuffer + i) = '\0';

    return outputBuffer;
}

char* mid(const char* input_string, const int offset, const int length)
{
    char* outputBuffer = malloc(sizeof(char) * length + 1);
    if (outputBuffer == NULL)
    {
        fprintf(stderr, "Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    int x;
    // Copies the `length` of characters
    for (x = 0; x < length; x++)
    {
        // `offset` is decreased (-) by one because we start at 0 not 1
        *(outputBuffer + x) = *(input_string + offset - 1 + x);
        // Catch overflows & termination characters
        if (*(outputBuffer + x) == '\0') break;
    }
    // Cap the string
    *(outputBuffer + x) = '\0';

    return outputBuffer;
}

char* right(const char* input_string, const int length)
{
    char* outputBuffer = malloc(sizeof(char) * length + 1);
    if (outputBuffer == NULL)
    {
        fprintf(stderr, "Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    // Uses the pointer `start` as the offset to retain for later the address in variable `input_string`
    const char* start = input_string;
    // Searches for the end of the string/terminating character
    while (*start != '\0')
        start++;

    // Adjusts the pointer to reference to the right end of where the string starts
    start -= length;
    // Checks if the pointer is still within the bounds of the string
    if (start < input_string)
        exit(EXIT_FAILURE);

    int x;
    // Copies the string from the offset to the end of the string to the output buffer
    for (x = 0; x < length; x++)
        *(outputBuffer + x) = *(start + x);

    // Terminate the string
    *(outputBuffer + x) = '\0';

    return outputBuffer;
}

int main()
{
    const char string[] = "Slice me, dice me, make Julienne fries!";

    printf("Original string: %s\n", string);

    char* left_string = left(string, 8);
    printf("Left %d characters: %s\n", 8, left_string);

    char* mid_string = mid(string, 11, 7);
    printf("Mid %d characters: %s\n", 7, mid(string, 11, 7));

    char* right_string = right(string, 20);
    printf("Right %d characters: %s\n", 20, right(string, 20));

    free(left_string);
    free(mid_string);
    free(right_string);

    return 0;
}
