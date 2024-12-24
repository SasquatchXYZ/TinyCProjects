#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    int ch, r;

    // Seed the random number generator
    srand((unsigned)time(NULL));

    while ((ch = getchar()) != EOF)
    {
        r = rand() % 2; // Generate a random number between 0 and 1

        if (r)
            putchar(toupper(ch));
        else
            putchar(tolower(ch));
    }

    return 0;
}
