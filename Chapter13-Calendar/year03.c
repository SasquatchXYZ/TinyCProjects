#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COLUMNS 3

void center(const char* text, const int width)
{
    const int length = strlen(text);
    if (length < width)
    {
        int s;
        const int indent = (width - length) / 2;
        for (s = 0; s < indent; s++)
            putchar(' ');

        while (*text)
        {
            putchar(*text);
            text++;
            s++;
        }

        for (; s < width; s++)
            putchar(' ');
    }
    else
    {
        for (int x = 0; x < width; x++)
            putchar(*text++);
    }
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
    int dotm[12];
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
    dotm[0] = weekday;
    int month;

    for (month = 1; month < 12; month++)
    {
        dotm[month] = (mdays[month - 1] + dotm[month - 1]) % 7;
    }

    for (month = 0; month < 12; month += COLUMNS)
    {
        int c, day, dow;
        for (c = 0; c < COLUMNS; c++)
        {
            sprintf(title, "%s %d", months[month + c], year);
            center(title, output_width);
            printf("   ");
        }
        putchar('\n');

        for (c = 0; c < COLUMNS; c++)
        {
            printf("Sun Mon Tue Wed Thu Fri Sat   ");
        }
        putchar('\n');

        // This loop outputs the first week of every month
        for (c = 0; c < COLUMNS; c++)
        {
            day = 1;
            for (dow = 0; dow < 7; dow++)
            {
                if (dow < dotm[month + c])
                {
                    printf("    ");
                }
                else
                {
                    printf(" %2d ", day);
                    day++;
                }
            }
            printf("  ");
            // Save the day-of-the-month for output on the next row's Sunday position
            dotm[month + c] = day;
        }
        putchar('\n');

        for (int week = 1; week < 6; week++)
        {
            for (c = 0; c < COLUMNS; c++)
            {
                day = dotm[month + c];
                for (dow = 0; dow < 7; dow++)
                {
                    if (day <= mdays[month + c])
                        printf(" %2d ", day);
                    else
                        printf("    ");
                    day++;
                }
                printf("  ");
                dotm[month + c] = day;
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
