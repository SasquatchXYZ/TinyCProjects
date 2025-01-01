#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void line_out(const int offset, const int length, const unsigned char* data)
{
    // Output the offset value
    printf("%05X ", offset);

    int a;
    // First loop for the hex values
    for (a = 0; a < length; a++)
    {
        // Calculation is based on the start of the data + the looping value
        printf(" %02X", *(data + a));
        // Add an extra space for readability after the eighth\ hex byte
        if ((a + 1) % 8 == 0)
            putchar(' ');
    }

    // Add a space after the hex columns
    putchar(' ');

    // Second loop for the ASCII values
    for (a = 0; a < length; a++)
    {
        // Checks the printable character range
        if (*(data + a) >= ' ' && *(data + a) <= '~')
            putchar(*(data + a)); // Outputs a printed character
        else
            putchar(' '); // Else outputs a space
    }

    putchar('\n');
}

int main(const int argc, char* argv[])
{
    unsigned char data[256];
    const int length = 16;

    // Seed the randomizer
    srand(time(NULL));

    int b;
    // Fill the array with random byte values, 0 through 255
    for (b = 0; b < 256; b++)
        data[b] = rand() % 256;

    for (b = 0; b < 256; b += length)
        line_out(b, length, data + b);

    return 0;
}
