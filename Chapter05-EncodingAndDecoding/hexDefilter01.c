#include <stdio.h>

int toHex(int c)
{
    if (c >= '0' && c <= '9') // Eliminates the digits 0 through 9
        return c - '0'; // Returns the digit's integer value
    if (c >= 'A' && c <= 'F') // Eliminates the letters A through F
        return c - 'A' + 0xA; // Returns the character's hex value: 'A' == 0x0A
    return -1; // All other characters return -1.
}

int main()
{
    while (1) // Endless loop that relies on the presence of an EOF to terminate
    {
        int ch = getchar();
        if (ch == EOF) break;

        int a = toHex(ch); // Converts the character to a hex value

        if (a < 0) break; // Exits if the character isn't hex

        a <<= 4; // Shifts value `a` four bits to represent the upper half of the byte in value

        ch = getchar(); // Repeats for the next character, but without the shift
        if (ch == EOF) break;

        int b = toHex(ch);

        if (b < 0) break;
        putchar(a + b); // Outputs the resulting byte
    }
}
