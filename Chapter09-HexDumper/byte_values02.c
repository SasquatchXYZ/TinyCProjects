#include <stdio.h>

int main()
{
    // Room for the full variety of byte values
    unsigned char data[256];
    int b;

    // Fill the array with byte values 0 to 255
    for (b = 0; b < 256; b++)
        data[b] = b;

    // Outputs the array, with each value on its own line
    for (b = 0; b < 256; b++)
        printf("%d\n", data[b]);

    return 0;
}
