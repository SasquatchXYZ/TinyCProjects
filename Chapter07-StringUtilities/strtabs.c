#include <ctype.h>
#include <stdio.h>

void strtabs(const char* s, const int tab)
{
    int column = 0;
    while (*s)
    {
        if (*s == '\t')
        {
            int spaces = tab - (column % tab);
            for (int x = 0; x < spaces; x++)
                putchar(' ');
            column += spaces;
        }
        else
        {
            putchar(*s);
            if (*s == '\n')
                column = 0;
            else
                column++;
        }
        s++;
    }
}

int main()
{
    const char* text[3] = {
        "Hello\tHi\tHowdy\n",
        "\tLa\tLa\n",
        "Constantinople\tConstantinople\n"
    };

    for (int y = 4; y < 32; y *= 2)
    {
        printf("Tab width: %d\n", y);
        for (int x = 0; x < 3; x++)
        {
            strtabs(text[x], y);
        }
    }

    return 0;
}
