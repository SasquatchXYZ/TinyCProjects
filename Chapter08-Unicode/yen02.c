#include <wchar.h>
#include <locale.h>

int main()
{
    wchar_t s[] = L"That will be $500\n";

    setlocale(LC_CTYPE, "en_US.UTF-8");

    // The character is specified by its Unicode value, U-00A5
    s[13] = 0xa5;

    // The `%lc` placeholder represents the wide character value in yen
    wprintf(L"%ls", s);

    return 0;
}
