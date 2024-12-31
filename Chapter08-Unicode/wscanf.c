#include <wchar.h>
#include <locale.h>

int main()
{
    const wchar_t pound = 0xa3;

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"How many crisps do you want? ");

    int quantity;
    wscanf(L"%d", &quantity);

    const float total = quantity * 1.4;

    wprintf(L"That will be %lc%.2f\n",
            pound,
            total);

    return 0;
}
