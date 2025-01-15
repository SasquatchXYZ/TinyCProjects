#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

    struct tm date;

    if (argc < 2)
    {
        time_t now;
        time(&now);
        struct tm* today = localtime(&now);
        date.tm_year = today->tm_year;
    }
    else
    {
        date.tm_year = strtol(argv[1], NULL, 10) - 1900;
    }

    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    putenv("TZ=GMT");
    tzset();
    mktime(&date);

    int weekday = date.tm_wday;
    const int year = date.tm_year + 1900;
    mdays[1] = february(year);

    int dow = 0; // The weekday loop variable, day-of-the-week
    // The outer loop pages through months of the year
    for (int month = 0; month < 12; month++)
    {
        sprintf(title, "%s %d", months[month], year);
        center(title, output_width);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        // The inner loop pages through the days of the month
        int day = 1;
        while (day <= mdays[month])
        {
            // The first week is special; variable `weekday` holds the first weekday
            // of the month.  Outputs blanks before then
            if (dow < weekday && day == 1)
            {
                printf("    ");
                dow++;
            }
            else
            {
                printf(" %2d ", day);
                dow++;
                if (dow > 6) // Checks for weekday overflow
                {
                    dow = 0;
                    putchar('\n');
                }
                day++;

                // Tests for the end of the month
                if (day > mdays[month])
                    break;
            }
        }
        weekday = dow; // Sets the first day of the month for the next month
        dow = 0;
        printf("\n\n");
    }

    return 0;
}
