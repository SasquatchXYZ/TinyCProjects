#include <stdio.h>

int february(const int year)
{
    if (year % 400 == 0)
        return 29;

    if (year % 100 == 0)
        return 28;

    if (year % 4 != 0)
        return 28;

    return 29;
}

int main()
{
    for (int year = 1584; year <= 2101; year++)
    {
        if (february(year) == 29)
            printf("%d\n", year);
    }

    return 0;
}
