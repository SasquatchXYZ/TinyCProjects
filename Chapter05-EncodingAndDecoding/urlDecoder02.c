#include <ctype.h>
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
            const int a = toHex(ch);
            // Check for invalid hex digit
            if (a < 0) break;

            ch = getchar();
            if (ch == EOF) break;
            const int b = toHex(ch);
            // Check for invalid hex digit
            if (b < 0) break;

            // Outputs the proper character value
            putchar((a << 4) + b);
        }
        else
        {
            if (ch == '-' || ch == '.' || ch == '_' || ch == '*')
                putchar(ch);
            else if (isalnum(ch))
                putchar(ch);
            else
            {
                // Illegal character found...
                fprintf(stderr, "\nInvalid character - D: '%d' C: '%c'\n", ch, ch);
                break;
            }
        }
    }

    return 0;
}
