#include <wchar.h>

int main()
{
    wchar_t hello[] = L"Hello, Wide World!\n";

    wprintf(L"%ls", hello);

    return 0;
}
