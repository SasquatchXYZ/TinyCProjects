#include <stdio.h>
#include <string.h>
#include <time.h>
#include <_stdlib.h>

void center(const char* text, const int width)
{
    const int len = strlen(text);
    const int left = (width - len) / 2;
    const int right = width - len - left;
    printf("%*s%s%*s\n", left, "", text, right, "");
}

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

int main(const int argc, const char* argv[])
{
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int output_width = 27;
    char title[output_width];

    time_t now;
    time(&now);
    struct tm* date = localtime(&now);

    if (argc >= 3)
    {
        const int selected_month = strtol(argv[1], NULL, 10);
        const int selected_year = strtol(argv[2], NULL, 10);
        const int selected_day = argc > 3
                                     ? strtol(argv[3], NULL, 10)
                                     : 1;
        if (selected_month > 0 && selected_month < 13)
        {
            date->tm_mon = selected_month - 1;
            date->tm_year = selected_year - 1900;
            date->tm_mday = selected_day;
            mktime(date);
        }
    }

    const int month = date->tm_mon;
    const int today = date->tm_mday;
    const int weekday = date->tm_wday;
    const int year = date->tm_year + 1900;
    mdays[1] = february(year);
    const int first = the_first(weekday, today);

    sprintf(title, "%s %d", months[month], year);
    center(title, output_width);
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
