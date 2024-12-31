#include <wchar.h>
#include <locale.h>

int main()
{
    const int count = 4;
    const wchar_t suits[count] = {
        // Unicode values for the four playing card suits
        0x2660, 0x2665, 0x2663, 0x2666
    };

    // The locale is set because these are not ASCII characters
    setlocale(LC_CTYPE, "en_US.UTF-8");

    for (int i = 0; i < count; i++)
        // The `putwchar()` function outputs each wide character value
        putwchar(suits[i]);
    putwchar('\n');

    return 0;
}
