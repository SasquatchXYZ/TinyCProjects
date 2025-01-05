#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

void line_out(const int offset, const int length, const unsigned char* data)
{
    // Output the offset value
    printf("%05X ", offset);

    int a;
    for (a = 0; a < length; a++)
    {
        printf(" %02X", *(data + a));
        if ((a + 1) % 8 == 0)
            putchar(' ');
    }

    // Handle lines with a length less than 16, i.e. last line of the file
    if (length < SIZE)
    {
        for (; a < SIZE; a++)
        {
            printf("   ");
            if ((a + 1) % 8 == 0)
                putchar(' ');
        }
    }

    putchar(' ');

    for (a = 0; a < length; a++)
    {
        if (*(data + a) >= ' ' && *(data + a) <= '~')
            putchar(*(data + a));
        else
            putchar(' ');
    }

    putchar('\n');
}

int main(const int argc, char* argv[])
{
    char filename[BUFSIZ];

    // If no commandline arguments typed...
    if (argc < 2)
    {
        printf("Filename: ");
        char* r = fgets(filename, BUFSIZ, stdin);

        if (filename == NULL || r == NULL || filename[0] == '\n')
        {
            printf("No file selected.\n");
            exit(1);
        }

        while (*r != '\n')
        {
            r++;
            if (r - filename == BUFSIZ)
                exit(1);
        }
        *r = '\0';
    }
    else
    {
        strcpy(filename, argv[1]);
    }

    const FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    unsigned char buffer[SIZE];
    int index = 0;
    int offset = 0;
    // Loops until the end of the file is encountered
    while (!feof(fp))
    {
        // Fetches a character
        const int ch = fgetc(fp);
        if (ch == EOF)
        {
            if (index != 0) // If the index is 0, the buffer is empty; otherwise...
                line_out(offset, index, buffer); // ...it outputs the final line of the hex dump
            break; // Terminate the loop
        }

        buffer[index] = ch; // Adds the character to the buffer
        index++;

        if (index == SIZE) // If the buffer is full, output a row of the hex dump
        {
            line_out(offset, SIZE, buffer);
            offset += SIZE;
            index = 0; // Reset the offset to start reading the next 16 bytes
        }
    }

    fclose(fp);

    return 0;
}
