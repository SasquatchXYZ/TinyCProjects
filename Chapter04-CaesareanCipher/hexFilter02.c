#include <stdio.h>

int main()
{
    int ch;

    int wrap = 0;
    while ((ch = getchar()) != EOF)
    {
        printf("%02X ", ch);
        wrap += 3;

        if (wrap > 77 || ch == '\n')
        {
            putchar('\n');
            wrap = 0;
        }
    }

    return 0;
}
