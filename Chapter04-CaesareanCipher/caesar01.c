#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch)) // Only processes alphabet characters
        {
            if (toupper(ch) >= 'A' && toupper(ch) <= 'M') // Searches for "A" through "M" or "a" through "m"
                ch += 13; // Rotates (shift) up for the lower half of the alphabet
            else
                ch -= 13; // Otherwise, rotates (shift) down
        }
        putchar(ch);
    }

    return 0;
}
