#include <stdio.h>
#include <unistd.h>

int main(const int argc, char* argv[])
{
    int r;
    opterr = 0;

    while ((r = getopt(argc, argv, "abc")) != -1)
    {
        switch (r)
        {
        case 'a':
            puts("alfa option set");
            break;
        case 'b':
            puts("beta option set");
            break;
        case 'c':
            puts("charlie option set");
            break;
        case '?':
            printf("Switch '%c' is invalid\n", optopt);
            break;
        default:
            puts("Unknown option");
        }
    }

    return 0;
}
