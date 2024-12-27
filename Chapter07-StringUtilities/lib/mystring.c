/* mystring library */
/* 26 December 2024 */
/* Dalton Ricker */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    Return the left portion of a string
    input_string = string
    length = length to cut from the left
    Return value: new string
 */
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

/*
    Return the middle portion of a string
    input_string = string
    offset = charater number into the string where to start
    length = length to cut from the middle
    Return value: new string
 */
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

/*
    Return the right portion of a string
    input_string = string
    length = length to cut from the right
    Return value: new string
 */
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

/*
    Capitalize the first letter of words in a string
    s = string
    Returned value: nothing, string is altered directly
 */
void strcaps(char* s)
{
    enum { FALSE, TRUE };
    int inword = FALSE;

    while (*s)
    {
        if (isalpha(*s))
        {
            if (!inword)
            {
                *s = (char)toupper(*s);
                inword = TRUE;
            }
        }
        else
        {
            inword = FALSE;
        }
        s++;
    }
}

/*
    Insert one string into another
    original_string = string
    insert_string = string to insert into the original
    offset = where to insert the string
    Return value: new string
 */
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

/*
    Convert a string to lowercase
    s = string
    Return value: nothing, string is altered directly
 */
void strlower(char* s)
{
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z')
        {
            *s += 32;
        }
        s++;
    }
}

/*
    Reverse characters in a a string
    s = string
    Return value: String with reverese text
 */
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

/*
    Split a string into two parts
    input_string = string to split
    offset = location of the split
    side1 = address for the first part of the string
    side2 = address for the second part of the string
    Return value: 0, error; 1, success
 */
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

/*
    Output text with a specific tab stop
    s = string to output
    tab = tab stop interval
    Return value: nothing
 */
void strtabs(const char* s, const int tab)
{
    int column = 0;
    while (*s)
    {
        if (*s == '\t')
        {
            int spaces = tab - (column % tab);
            for (int x = 0; x < spaces; x++)
                putchar(' ');
            column += spaces;
        }
        else
        {
            putchar(*s);
            if (*s == '\n')
                column = 0;
            else
                column++;
        }
        s++;
    }
}

/*
    Convert a string to uppercase
    s = string to convert
    Return value: nothing
 */
void strupper(char* s)
{
    while (*s)
    {
        if (*s >= 'a' && *s <= 'z')
        {
            *s &= 0xdf;
        }
        s++;
    }
}

/*
    Count the number of words in a string
    s = string
    Return value: number of words in the string
 */
int strwordcount(char* s)
{
    enum { FALSE, TRUE };
    int inword = FALSE;
    int count = 0;

    while (*s)
    {
        // If we encounter a space...
        if (isspace(*s))
        {
            // ...and we were IN a word...
            if (inword)
            {
                // increase the word count
                count++;
                // now we are no longer in a word
                inword = FALSE;
            }
        }
        else
        {
            // We are still in a word
            inword = TRUE;
        }
        s++;
    }

    // If we are still in a word at the end then count it
    if (inword == TRUE)
        count++;

    return count;
}
