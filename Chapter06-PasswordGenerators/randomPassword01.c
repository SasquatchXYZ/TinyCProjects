#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int PASSWORD_LENGTH = 10;

    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        // Sets the range of random values to printable characters
        const char ch = rand() % ('~' - '!' + 1);
        putchar(ch + '!');
    }
    putchar('\n');

    return 0;
}
