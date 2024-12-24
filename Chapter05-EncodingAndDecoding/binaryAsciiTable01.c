#include <stdio.h>

char* binaryString(char a)
{
    static char binary[9];
    int i = 0;
    while (i < 8)
    {
        binary[i] = a & 0x80 ? '1' : '0';
        a <<= 1;
        i++;
    }
    binary[i] = '\0';
    return binary;
}

int main(void)
{
    // Output the header row, all columns or `sticks`
    printf("Dec  Hex  Binary   C | Dec  Hex  Binary   C | Dec  Hex  Binary   C | Dec  Hex  Binary   C\n");

    for (int i = 0; i < 32; i++)
    {
        // First Stick
        printf("%3d  %02X  %s  - | ", i, i, binaryString(i));
        // Second Stick
        printf("%3d  %02X  %s  %c | ", i + 32, i + 32, binaryString(i + 32), i + 32);
        // Third Stick
        printf("%3d  %02X  %s  %c | ", i + 64, i + 64, binaryString(i + 64), i + 64);
        // Fourth Stick
        printf("%3d  %02X  %s  %c \n", i + 96, i + 96, binaryString(i + 96), i + 96);
    }

    return 0;
}
