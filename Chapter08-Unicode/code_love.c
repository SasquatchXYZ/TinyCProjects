#include <wchar.h>
#include <locale.h>

int main()
{
    wchar_t s[] = L"I * to code\n";

    setlocale(LC_ALL, "en_US.UTF-8");

    // The heart character is specified by its Unicode value, U-2665
    s[2] = 0x2665;

    fputws(s, stdout);

    return 0;
}
