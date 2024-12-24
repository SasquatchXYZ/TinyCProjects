#include <stdio.h>

int main()
{
    int ch; // I/O deals with integers, not characters

    while ((ch = getchar()) != EOF) // Reads input until the end of file is encountered; EOF is an integer value.
    {
        switch (ch)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            putchar('*');
            break;
        default:
            putchar(ch);
        }
    }
    return 0;
}
