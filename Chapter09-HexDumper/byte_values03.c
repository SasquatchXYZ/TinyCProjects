#include <stdio.h>

int main()
{
    // Room for the full variety of byte values
    unsigned char data[256];
    int b;

    // Fill the array with byte values 0 to 255
    for (b = 0; b < 256; b++)
        data[b] = b;

    // Outputs the array, with each value on its own line as hexidecimals
    for (b = 0; b < 256; b++)
    {
        printf(" %02X", data[b]);
        // We add one to the value of `b` to avoid a newline
        // popping out after the first value (zero)
        if ((b + 1) % 16 == 0)
            putchar('\n');
    }

    return 0;
}
