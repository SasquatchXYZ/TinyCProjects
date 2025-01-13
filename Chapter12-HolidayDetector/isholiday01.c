#include <stdio.h>
#include <time.h>

int is_holiday(const struct tm* date)
{
    // New Years Day
    if (date->tm_mon == 0 && date->tm_mday == 1)
        return 1;

    // Juneteenth
    if (date->tm_mon == 5 && date->tm_mday == 19)
        return 1;

    // Independence Day
    if (date->tm_mon == 6 && date->tm_mday == 4)
        return 1;

    // Veterans Day
    if (date->tm_mon == 10 && date->tm_mday == 11)
        return 1;

    // Christmas Day
    if (date->tm_mon == 11 && date->tm_mday == 25)
        return 1;

    return 0;
}

int main()
{
    const time_t now = time(NULL);

    const struct tm* today = localtime(&now);

    printf("Today is %d/%02d/%d, ",
           today->tm_mon + 1,
           today->tm_mday,
           today->tm_year + 1900
    );

    const int r = is_holiday(today);

    if (r)
        puts("a holiday");
    else
        puts("not a holiday");

    return r;
}
