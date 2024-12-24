#include <stdio.h>

int main(void)
{
    // Output the header row, all columns or `sticks`
    printf("Dec  Oct  Hex  C | Dec  Oct  Hex  C | Dec  Oct  Hex  C | Dec  Oct  Hex  C\n");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < 32; i++)
    {
        // First Stick
        printf("%3d  %3o  %3x  - | ", i, i, i);
        // Second Stick
        printf("%3d  %3o  %3x  %c | ", i + 32, i + 32, i + 32, i + 32);
        // Third Stick
        printf("%3d  %3o  %3x  %c | ", i + 64, i + 64, i + 64, i +64);
        // Fourth Stick
        printf("%3d  %3o  %3x  %c \n", i + 96, i + 96, i + 96, i + 96);
    }

    return 0;
}
