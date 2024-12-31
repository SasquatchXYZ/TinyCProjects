#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    const wchar_t alpha = 0x391;
    const wchar_t omega = 0x3a9;
    const wchar_t no_sigma = 0x3a2;
    const char* file = "alphabeta.wtxt";

    FILE* fp = fopen(file, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", file);
        exit(EXIT_FAILURE);
    }

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"Writing the Greek alphabet...\n");

    // Loops through the Greek alphabet
    for (wchar_t a = alpha; a <= omega; a++)
    {
        // Tests for the blank spot and skips it
        if (a == no_sigma) continue;

        fputwc(a, fp); // Writes the Greek letter to the file
        fputwc(a, stdout); // Also sends the character to the standard output
    }

    // Writes a null terminator to the file
    // so that wide string file input functions can be used
    // to read it later
    fputwc('\0', fp);

    fclose(fp);

    wprintf(L"\nDone\n");

    return 0;
}
