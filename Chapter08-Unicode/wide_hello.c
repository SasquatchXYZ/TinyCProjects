#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    // Each array is created as a string,
    // including the newline and null characters
    const wchar_t russian[] = {
        0x41f, 0x440, 0x438, 0x432, 0x435, 0x442, '!', '\n', '\0'
    };

    const wchar_t chinese[] = {
        0x4f31, 0x597d, '\n', '\0'
    };

    const wchar_t emoji[] = {
        0x1f44b, '\n', '\0'
    };

    setlocale(LC_ALL, "en_US.UTF-8");
    // The `fputws()` function requires a wide string
    // and file handle as arguments
    fputws(russian, stdout);
    fputws(chinese, stdout);
    fputws(emoji, stdout);
}
