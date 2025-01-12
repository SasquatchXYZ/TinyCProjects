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

    int r;
    if (holiday->month == 5)
    {
        r = weekend(19, holiday->day, holiday->weekday);
        holiday->name = holiday_names[1];
        return r;
    }

    if (holiday->month == 6)
    {
        r = weekend(4, holiday->day, holiday->weekday);
        holiday->name = holiday_names[2];
        return r;
    }

    if (holiday->month == 10)
    {
        r = weekend(11, holiday->day, holiday->weekday);
        holiday->name = holiday_names[3];
        return r;
    }

    if (holiday->month == 11)
    {
        r = weekend(25, holiday->day, holiday->weekday);
        holiday->name = holiday_names[4];
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
