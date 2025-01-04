#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int options;

#define SIZE 16
#define ABBR 1
#define OCT 2
#define set_abbr() options |= ABBR
#define test_abbr() ((options & ABBR) == ABBR)
#define set_oct() options |= OCT
#define test_oct() ((options & OCT) == OCT)

void line_out(const int offset, const int length, const unsigned char* data)
{
    if (!test_abbr())
    {
        printf("%05X ", offset);
    }

    int a;
    for (a = 0; a < length; a++)
    {
        printf(" %02X", *(data + a));
        if ((a + 1) % 8 == 0 && !test_abbr())
            putchar(' ');
    }

    if (length < SIZE)
    {
        for (; a < SIZE; a++)
        {
            printf("   ");
            if ((a + 1) % 8 == 0)
                putchar(' ');
        }
    }

    if (!test_abbr())
    {
        putchar(' ');

        for (a = 0; a < length; a++)
        {
            if (*(data + a) >= ' ' && *(data + a) <= '~')
                putchar(*(data + a));
            else
                putchar(' ');
        }
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
    // optind = 2; // This is required to get it to work on MacOS because `getopt` behaves differently

    while ((r = getopt(argc, argv, "aoh")) != -1)
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
    for (index = optind; index < argc; index++)
    {
        printf("Non-option argument %s\n", argv[index]);
    }

    index = 0;
    while (!feof(fp))
    {
        const int ch = fgetc(fp);
        if (ch == EOF)
        {
            if (index != 0)
                line_out(offset, index, buffer);
            break;
        }

        buffer[index] = ch;
        index++;

        if (index == SIZE)
        {
            line_out(offset, SIZE, buffer);
            offset += SIZE;
            index = 0;
        }
    }

    fclose(fp);

    return 0;
}
