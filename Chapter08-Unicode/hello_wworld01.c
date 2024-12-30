#include <wchar.h> // Wide character definitions and functions

int main()
{
    // The `wprintf()` function is analogous to the `printf()` function.
    // The `L` prefix is required for a string composed of wide characters.
    // Even though the text here is ASCII, wide characters are used internally
    // to represent the characters.
    wprintf(L"Hello, Wide World!\n");

    return 0;
}
