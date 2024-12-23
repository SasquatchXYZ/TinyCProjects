#include <ctype.h>
#include <stdio.h>

int main()
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            putchar(toupper(ch));
        else
            putchar(ch);
    }

    return 0;
}
