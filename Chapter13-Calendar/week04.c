#include <stdio.h>
#include <time.h>

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
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t now;
    time(&now);
    const struct tm* date = localtime(&now);
    // Make sure February has the right value of days for the current year
    mdays[1] = february(date->tm_year + 1900);

    const int day = date->tm_mday;
    const int month = date->tm_mon;
    int pmonth = month - 1;
    if (pmonth < 0)
        pmonth = 11;
    const int weekday = date->tm_wday;
    const int sunday = day - weekday;
    int weekno = (9 + date->tm_yday - weekday) / 7;
    if (weekno == 0)
        weekno = 52;

    // Print the month name
    if (sunday < 1)
        printf("  %s / %s", months[pmonth], months[month]);
    else if (sunday + 6 > mdays[month])
    {
        if (month == 11)
            printf("  %s / %s", months[month], months[0]);
        else
            printf("  %s / %s", months[month], months[month + 1]);
    }
    else
        printf("  %s", months[month]);

    printf(" - Week %d\n", weekno);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int d = sunday; d < sunday + 7; d++)
    {
        if (d < 1)
            printf(" %2d ", mdays[pmonth] + d);
        else if (d > mdays[month])
            printf(" %2d ", d - mdays[month]);
        else
        {
            if (d == day)
                printf("[%2d]", d);
            else
                printf(" %2d ", d);
        }
    }
    putchar('\n');

    return 0;
}
