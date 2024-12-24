#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;

    const int shift = 'D' - 'A'; // Shifts from A to D, which is done backward here because math

    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch)) // Handles letters specifically
        {
            ch += shift; // Shifts the letter
            if ((ch > 'Z' && ch < 'a') || ch > 'z') // Determines whether the new character is out of range
                ch -= 26; // if so, adjusts its value back in range
        }
        putchar(ch);
    }

    return 0;
}
