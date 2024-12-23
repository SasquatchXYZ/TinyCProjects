#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int ch, r;

    r = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
            r = 1;

        if (r % 2 != 0)
            putchar(toupper(ch));
        else
            putchar(tolower(ch));
        r++;
    }

    return 0;
}
