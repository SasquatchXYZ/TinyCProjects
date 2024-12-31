#include <wchar.h>
#include <locale.h>

// Remove the `\n` from wide string str
void newline_strip(wchar_t* str)
{
    // Loop until the null char is found
    while (*str)
    {
        // Upon finding the newline...
        if (*str == '\n')
        {
            // ...replace it with the null char
            *str = '\0';
            // and return
            return;
        }
        str++;
    }
}

int main()
{
    const int size = 32;
    wchar_t input[size];

    setlocale(LC_CTYPE, "UTF-8");

    wprintf(L"Type some fancy text:😁 ");
    fgetws(input, size, stdin);

    newline_strip(input);

    wprintf(L"You typed: '%ls'\n", input);

    return 0;
}
