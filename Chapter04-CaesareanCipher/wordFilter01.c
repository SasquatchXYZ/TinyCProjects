#include <stdio.h>
#include <ctype.h>

// The word size is set here; this way, you can update the buffer size
// in a single spot, and various other parts of the code are updated
// to reflect the change.
#define WORD_SIZE 64

int main()
{
    char word[WORD_SIZE];
    int ch;

    int offset = 0; // Initializes the offset value
    while ((ch = getchar()) != EOF)
    {
        // The `isspace()` function returns TRUE for whitespace characters,
        // marking the end of the word
        if (isspace(ch))
        {
            word[offset] = '\0'; // Always cap your strings
            if (offset > 0) // Ensures the buffer has text in it to print
                printf("%s\n", word); // Outputs the buffer's contents on a line by itself
            offset = 0; // Resets the offset
        }
        // Handles printable characters
        else
        {
            word[offset] = ch; // Stores the character
            offset++; // Increments the offset
            if (offset == WORD_SIZE - 1) // Checks for potential overflow, a full buffer
            {
                word[offset] = '\0'; // Caps the string
                printf("%s\n", word); // Outputs the word, dumping the buffer
                offset = 0; // Resets the offset
            }
        }
    }

    return 0;
}
