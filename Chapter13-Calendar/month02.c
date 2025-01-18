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

int the_first(const int wday, const int mday)
{
    int first = wday - (mday % 7) + 1;
    if (first < 0)
        first += 7;

    return first;
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

    const int month = date->tm_mon;
    const int today = date->tm_mday;
    const int weekday = date->tm_wday;
    const int year = date->tm_year + 1900;
    mdays[1] = february(year);
    const int first = the_first(weekday, today);

    printf("%s %d\n", months[month], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int day = 1;
    while (day <= mdays[month])
    {
        for (int d = 0; d < 7; d++)
        {
            if (d < first && day == 1)
            {
                printf("    ");
            }
            else
            {
                if (day == today)
                    printf("[%2d]", day);
                else
                    printf(" %2d ", day);

                day++;

                if (day > mdays[month])
                    break;
            }
        }
        putchar('\n');
    }

    return 0;
}
