#include <wchar.h>
#include <locale.h>

int main()
{
    // The character is specified by its Unicode value, U-00A5
    const wchar_t yen = 0xa5;

    setlocale(LC_CTYPE, "en_US.UTF-8");

    // The `%lc` placeholder represents the wide character value in yen
    wprintf(L"That will be %lc500\n", yen);

    return 0;
}
