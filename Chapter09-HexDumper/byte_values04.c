#include <stdio.h>

int main()
{
    // Room for the full variety of byte values
    unsigned char data[256];
    int b;

    // Fill the array with byte values 0 to 255
    for (b = 0; b < 256; b++)
        data[b] = b;

    // Dump the data
    for (b = 0; b < 256; b++)
    {
        if (b % 16 == 0) // At the start of every line
            printf("%05X ", b); // Output the offset

        printf(" %02X", data[b]);

        if ((b + 1) % 8 == 0) // After the 8th column
            putchar(' '); // Add a space

        if ((b + 1) % 16 == 0) // After 16 bytes
            putchar('\n'); // Add a newline
    }

    return 0;
}
