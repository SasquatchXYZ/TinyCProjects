#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "en_US.UTF-8");
    const char* file = "alphabeta.wtxt";

    FILE* fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", file);
        exit(EXIT_FAILURE);
    }

    // Define a constant for the input buffer
    const int length = 64;
    wchar_t line[length];

    wprintf(L"Reading from %s:\n", file);
    fgetws(line, length, fp);
    wprintf(L"%ls\n", line);

    fclose(fp);

    return 0;
}
