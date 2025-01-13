#include <stdio.h>
#include <time.h>

#define FRIDAY 5
#define MONDAY 1

struct holiday
{
    int month;
    int day;
    int weekday;
    char* name;
};

// Struct must be passed as a pointer because the `name`
// member is modified within the function
int is_holiday(struct holiday* holiday)
{
    char* holiday_names[] = {
        "New Year's Day",
        "Juneteenth",
        "Independence Day",
        "Veterans Day",
        "Christmas Day"
    };

    if (holiday->month == 11 && holiday->day == 31 && holiday->weekday == FRIDAY)
    {
        holiday->name = holiday_names[0];
        return 2;
    }

    if (holiday->month == 0 && holiday->day == 1)
    {
        holiday->name = holiday_names[0];
        return 1;
    }

    if (holiday->month == 0 && holiday->day == 2 && holiday->weekday == MONDAY)
    {
        holiday->name = holiday_names[0];
        return 2;
    }

    if (holiday->month == 5)
    {
        if (holiday->day > 17 && holiday->day < 21)
        {
            if (holiday->day == 18 && holiday->weekday == FRIDAY)
            {
                holiday->name = holiday_names[1];
                return 2;
            }
            if (holiday->day == 20 && holiday->weekday == MONDAY)
            {
                holiday->name = holiday_names[1];
                return 2;
            }
            if (holiday->day == 19)
            {
                holiday->name = holiday_names[1];
                return 1;
            }
        }
    }

    if (holiday->month == 6)
    {
        if (holiday->day > 2 && holiday->day < 6)
        {
            if (holiday->day == 3 && holiday->weekday == FRIDAY)
            {
                holiday->name = holiday_names[2];
                return 2;
            }
            if (holiday->day == 5 && holiday->weekday == MONDAY)
            {
                holiday->name = holiday_names[2];
                return 2;
            }
            if (holiday->day == 4)
            {
                holiday->name = holiday_names[2];
                return 1;
            }
        }
    }

    if (holiday->month == 10)
    {
        if (holiday->day > 9 && holiday->day < 13)
        {
            if (holiday->day == 10 && holiday->weekday == FRIDAY)
            {
                holiday->name = holiday_names[3];
                return 2;
            }
            if (holiday->day == 12 && holiday->weekday == MONDAY)
            {
                holiday->name = holiday_names[3];
                return 2;
            }
            if (holiday->day == 11)
            {
                holiday->name = holiday_names[3];
                return 1;
            }
        }
    }

    if (holiday->month == 11)
    {
        if (holiday->day > 23 && holiday->day < 27)
        {
            if (holiday->day == 24 && holiday->weekday == FRIDAY)
            {
                holiday->name = holiday_names[4];
                return 2;
            }
            if (holiday->day == 26 && holiday->weekday == MONDAY)
            {
                holiday->name = holiday_names[4];
                return 2;
            }
            if (holiday->day == 25)
            {
                holiday->name = holiday_names[4];
                return 1;
            }
        }
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
