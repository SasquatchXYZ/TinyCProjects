#include <stdio.h>

int main()
{
    // Random assortment of 10 hex values
    int hexbytes[] = {
        0x41, 0x42, 0x43, 0x44, 0x45,
        0x46, 0x47, 0x48, 0x49, 0x4A,
    };

    int checksum = 0;
    for (int i = 0; i < 10; i++)
    {
        checksum += hexbytes[i];
        printf(" %02X", hexbytes[i]);
    }
    // Outputs the checksum, but limited to a char-size value
    printf("\nChecksum = %02X\n", checksum % 0x100);

    return 0;
}
