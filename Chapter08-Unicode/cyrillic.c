#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    const wchar_t ah = 0x410;
    const wchar_t ya = 0x42f;
    const char* file = "cyrillic.wtxt";

    FILE* fp = fopen(file, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", file);
        exit(EXIT_FAILURE);
    }

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"Writing the Cyrillic alphabet...\n");

    // Loops through the Cyrillic alphabet
    for (wchar_t ch = ah; ch <= ya; ch++)
    {
        fputwc(ch, fp); // Writes the Cyrillic letter to the file
        fputwc(ch, stdout); // Also sends the character to the standard output
    }

    // Writes a null terminator to the file
    // so that wide string file input functions can be used
    // to read it later
    fputwc('\0', fp);

    fclose(fp);

    wprintf(L"\nDone\n");

    return 0;
}
