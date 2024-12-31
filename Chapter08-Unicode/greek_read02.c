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

    wprintf(L"Reading from %s:\n", file);

    wint_t character;
    while ((character = fgetwc(fp)) != WEOF)
        putwchar(character);

    putwchar('\n');

    fclose(fp);

    return 0;
}
