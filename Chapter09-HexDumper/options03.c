#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(const int argc, char* argv[])
{
    if (argc < 2)
    {
        puts("Format: dumpfile filename [options]");
        exit(1);
    }

    const char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    printf("File '%s' opened\n", filename);
    fclose(fp);

    int r;
    opterr = 0;
    int bravo, charlie;
    int alfa = bravo = charlie = 0;
    while ((r = getopt(argc, argv, "abc")) != -1)
    {
        switch (r)
        {
        case 'a':
            alfa = 1;
            break;
        case 'b':
            bravo = 1;
            break;
        case 'c':
            charlie = 1;
            break;
        case '?':
            printf("Switch '%c' is invalid\n", optopt);
            break;
        default:
            puts("Unknown option");
        }
    }

    if (alfa) puts("Alfa option set");
    if (bravo) puts("Beta option set");
    if (charlie) puts("Charlie option set");
    if (alfa + bravo + charlie == 0) puts("No options set");
    return 0;
}
