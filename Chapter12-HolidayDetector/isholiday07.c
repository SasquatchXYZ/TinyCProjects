#include <stdio.h>
#include <time.h>
#include <math.h>

#define FRIDAY 5
#define MONDAY 1
#define THURSDAY 4
#define FIRST_WEEK holiday->day < 8
#define SECOND_WEEK holiday->day > 7 && holiday->day < 15
#define THIRD_WEEK holiday->day > 14 && holiday->day < 22
#define FOURTH_WEEK holiday->day > 21 && holiday->day < 29
#define LAST_WEEK holiday->day > 24 && holiday->day < 32

struct holiday
{
    int month;
    int day;
    int year;
    int weekday;
    char* name;
};

int easter(const struct holiday* holiday)
{
    const int Y = holiday->year;
    const int a = Y % 19;
    const double b = floor(Y / 100);
    const int c = Y % 100;
    const double d = floor(b / 4);
    const int e = (int)b % 4;
    const double f = floor((b + 8) / 25);
    const double g = floor((b - f + 1) / 3);
    const int h = (19 * a + (int)b - (int)d - (int)g + 15) % 30;
    const double i = floor(c / 4);
    const int k = c % 4;
    const int L = (32 + 2 * e + 2 * (int)i - h - k) % 7;
    const double m = floor((a + 11 * h + 22 * L) / 451);
    const double month = floor((h + L - 7 * m + 114) / 31) - 1;
    const double day = ((h + L - 7 * (int)m + 114) % 31) + 1;

    if (holiday->month == month && holiday->day == day)
        return 1;
    else
        return 0;
}

int weekend(const int holiday, const int monthday, const int weekday)
{
    if (monthday > holiday - 2 && monthday < holiday + 2)
    {
        if (monthday == holiday - 1 && weekday == FRIDAY)
            return 2;

        if (monthday == holiday + 1 && weekday == MONDAY)
            return 2;

        if (monthday == holiday)
            return 1;
    }
    return 0;
}

// Struct must be passed as a pointer because the `name`
// member is modified within the function
int is_holiday(struct holiday* holiday)
{
    char* holiday_names[] = {
        "New Year's Day",
        "Martin Luther King Jr. Day",
        "Presidents Day",
        "Memorial Day",
        "Juneteenth",
        "Independence Day",
        "Labor Day",
        "Columbus Day",
        "Veterans Day",
        "Thanksgiving",
        "Christmas",
        "Easter"
    };

    enum
    {
        JANUARY, FEBRUARY, MARCH, APRIL,
        MAY, JUNE, JULY, AUGUST,
        SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };

    // New Years Day
    if (holiday->month == DECEMBER && holiday->day == 31 && holiday->weekday == FRIDAY)
    {
        holiday->name = holiday_names[0];
        return 2;
    }

    if (holiday->month == JANUARY && holiday->day == 1)
    {
        holiday->name = holiday_names[0];
        return 1;
    }

    if (holiday->month == JANUARY && holiday->day == 2 && holiday->weekday == MONDAY)
    {
        holiday->name = holiday_names[0];
        return 2;
    }

    // Martin Luther King Jr. Day
    if (holiday->month == JANUARY && holiday->weekday == MONDAY)
    {
        if (THIRD_WEEK)
        {
            holiday->name = holiday_names[1];
            return 1;
        }
    }

    // Presidents Day
    if (holiday->month == FEBRUARY && holiday->weekday == MONDAY)
    {
        if (THIRD_WEEK)
        {
            holiday->name = holiday_names[2];
            return 1;
        }
    }

    // Memorial Day
    if (holiday->month == MAY && holiday->weekday == MONDAY)
    {
        if (LAST_WEEK)
        {
            holiday->name = holiday_names[3];
            return 1;
        }
    }

    int r;
    // Juneteenth
    if (holiday->month == JUNE)
    {
        r = weekend(19, holiday->day, holiday->weekday);
        holiday->name = holiday_names[4];
        return r;
    }

    // Independence Day
    if (holiday->month == JULY)
    {
        r = weekend(4, holiday->day, holiday->weekday);
        holiday->name = holiday_names[5];
        return r;
    }

    // Labor Day
    if (holiday->month == SEPTEMBER && holiday->weekday == MONDAY)
    {
        if (FIRST_WEEK)
        {
            holiday->name = holiday_names[6];
            return 1;
        }
    }

    // Columbus Day
    if (holiday->month == OCTOBER && holiday->weekday == MONDAY)
    {
        if (SECOND_WEEK)
        {
            holiday->name = holiday_names[7];
            return 1;
        }
    }

    if (holiday->month == NOVEMBER)
    {
        // Thanksgiving
        if (holiday->weekday == THURSDAY && FOURTH_WEEK)
        {
            holiday->name = holiday_names[9];
            return 1;
        }

        // Veterans Day
        r = weekend(11, holiday->day, holiday->weekday);
        holiday->name = holiday_names[8];
        return r;
    }

    // Christmas
    if (holiday->month == DECEMBER)
    {
        r = weekend(25, holiday->day, holiday->weekday);
        holiday->name = holiday_names[10];
        return r;
    }

    // Easter
    r = easter(holiday);
    if (r == 1)
    {
        holiday->name = holiday_names[11];
        return r;
    }

    return 0;
}

int main()
{
    const time_t now = time(NULL);

    const struct tm* today = localtime(&now);

    struct holiday holiday;
    holiday.month = today->tm_mon;
    holiday.day = today->tm_mday;
    holiday.year = today->tm_year + 1900;
    holiday.weekday = today->tm_wday;
    holiday.name = NULL;

    printf("Today is %d/%02d/%d, ",
           today->tm_mon + 1,
           today->tm_mday,
           today->tm_year + 1900
    );

    const int r = is_holiday(&holiday);

    if (r == 1)
        puts(holiday.name);
    else if (r == 2)
        printf("%s observed\n", holiday.name);
    else
        puts("not a holiday");

    return r;
}
