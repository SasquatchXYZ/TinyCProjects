#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Declares the external variable before it's used
int options;

#define SIZE 16
#define ABBR 1 // Abbreviation is status bit 1
#define OCT 2 // Octal output is status bit 2
// Uses the bitwise logical OR to set bit 1 (ABBR) in variable `options`
#define set_abbr() options |= ABBR
// Uses the bitwise logical AND to test bit 1 (ABBR) in variable `options`
#define test_abbr() ((options & ABBR) == ABBR)
// Uses the bitwise logical OR to set bit 2 (OCT) in variable `options`
#define set_oct() options |= OCT
// Uses the bitwise logical AND to test bit 2 (OCT) in variable `options`
#define test_oct() ((options & OCT) == OCT)

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

void help(void)
{
    puts("dumpfile - output a file's raw data");
    puts("Format: dumpfile filename [options]");
    puts("Options:");
    puts("-a: Abbreviated output");
    puts("-o: Output Octal instead of Hex");
    puts("-h: Display this help text");
    exit(1);
}

int main(const int argc, char* argv[])
{
    if (argc < 2)
    {
        puts("Format: dumpfile filename [options]");
        exit(1);
    }

    char* filename = argv[1];

    if (strcmp(filename, "-h") == 0)
        help();

    const FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    unsigned char buffer[SIZE];
    int index;
    int r;
    int offset = index = opterr = options = 0;

    while ((r = getopt(argc, argv, "aoh")) != 1)
    {
        switch (r)
        {
        case 'a':
            set_abbr();
            break;
        case 'o':
            set_oct();
            break;
        case 'h':
            help();
        case '?':
            printf("Switch '%c' not valid\n", optopt);
            break;
        default:
            puts("Unknown option");
        }
    }

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
