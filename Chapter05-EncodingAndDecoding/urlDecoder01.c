#include <stdio.h>

int toHex(int c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 0xA);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 0xA);
    return -1;
}

int main()
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        // Checks for the % sign and grabs the next two characters
        if (ch == '%')
        {
            ch = getchar();
            if (ch == EOF) break;
            int a = toHex(ch);
            ch = getchar();
            if (ch == EOF) break;
            int b = toHex(ch);
            // Outputs the proper character value
            putchar((a << 4) + b);
        }
        else
            putchar(ch);
    }

    return 0;
}
