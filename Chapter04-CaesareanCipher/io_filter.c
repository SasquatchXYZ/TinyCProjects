#include <stdio.h>

int main()
{
    int ch; // I/O deals with integers, not characters

    while ((ch = getchar()) != EOF) // Reads input until the end of file is encountered; EOF is an integer value.
        putchar(ch); // Spews output

    return 0;
}
