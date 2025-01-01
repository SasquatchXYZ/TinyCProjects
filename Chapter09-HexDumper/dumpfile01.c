#include <stdio.h>
#include <stdlib.h>

void line_out(const int offset, const int length, const unsigned char* data)
{
    // Output the offset value
    printf("%05X ", offset);

    int a;

    // First loop for the hex values
    for (a = 0; a < length; a++)
    {
        // Calculation is based on the start of the data + the looping value
        printf(" %02X", *(data + a));
        // Add an extra space for readability after the eighth\ hex byte
        if ((a + 1) % 8 == 0)
            putchar(' ');
    }

    // Add a space after the hex columns
    putchar(' ');

    // Second loop for the ASCII values
    for (a = 0; a < length; a++)
    {
        // Checks the printable character range
        if (*(data + a) >= ' ' && *(data + a) <= '~')
            putchar(*(data + a)); // Outputs a printed character
        else
            putchar(' '); // Else outputs a space
    }

    putchar('\n');
}

int main(const int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Format: dumpfile filename\n");
        exit(1);
    }

    const char* filename = argv[1];
    const FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    const int length = 16;
    unsigned char buffer[length];
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

        if (index == length) // If the buffer is full, output a row of the hex dump
        {
            line_out(offset, length, buffer);
            offset += length;
            index = 0; // Reset the offset to start reading the next 16 bytes
        }
    }

    fclose(fp);

    return 0;
}
