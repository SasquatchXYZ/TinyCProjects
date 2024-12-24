#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE * 3 + 3 + 1)

int main()
{
    char line[LENGTH];
    int ch, hex;
    float version;

    // Check for proper file format - first line
    char* r = fgets(line, LENGTH, stdin);
    if (r == NULL || strncmp(line, "HEX ENCODE", 10) != 0)
    {
        fprintf(stderr, "Invalid HEX ENCODE data\n");
        exit(1);
    }
    sscanf(line, "HEX ENCODE v%f", &version);

    int x = 0;
    int row = 0;
    while ((ch = getchar()) != EOF)
    {
        line[x] = ch;
        x++;
        if (ch == '\n' || x == LENGTH)
        {
            // Properly terminate the line
            if (line[x - 1] == '\n')
                line[x - 1] = '\0';
            else
                line[x] = '\0';

            // Stop processing on the last line
            if (strncmp(line, "HEX ENCODE END", 13) == 0)
                break;

            // Extract values
            int checksum = 0; // Reset the checksum
            int byteCount = 0;
            r = strtok(line, " ");
            while (r)
            {
                sscanf(r, "%02X", &hex);
                if (byteCount < BYTES_PER_LINE)
                {
                    checksum += hex;
                    printf("%c", hex);
                    r = strtok(NULL, " ");
                    byteCount++;
                }
                else
                {
                    // Validate
                    if (hex != checksum % 0x100)
                    {
                        // Bad checksum
                        fprintf(stderr, "\nChecksum error at Line %d\n", row);
                        fprintf(stderr, "Unable to decode data\n");
                        exit(1);
                        // The stdout buffer does flush at this point
                        // Your could eliminate the output, but it's kinda too late.
                    }
                    break;
                }
            }
            x = 0;
            row++;
        }
    }

    return 0;
}
