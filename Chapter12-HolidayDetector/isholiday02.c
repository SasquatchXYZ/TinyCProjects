#include <stdio.h>
#include <time.h>

struct holiday
{
    int month;
    int day;
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

    if (holiday->month == 0 && holiday->day == 1)
    {
        holiday->name = holiday_names[0];
        return 1;
    }

    if (holiday->month == 5 && holiday->day == 19)
    {
        holiday->name = holiday_names[1];
        return 1;
    }

    if (holiday->month == 6 && holiday->day == 4)
    {
        holiday->name = holiday_names[2];
        return 1;
    }

    if (holiday->month == 10 && holiday->day == 11)
    {
        holiday->name = holiday_names[3];
        return 1;
    }

    if (holiday->month == 11 && holiday->day == 25)
    {
        holiday->name = holiday_names[4];
        return 1;
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
    holiday.name = NULL;

    printf("Today is %d/%02d/%d, ",
           today->tm_mon + 1,
           today->tm_mday,
           today->tm_year + 1900
    );

    const int r = is_holiday(&holiday);

    if (r)
        puts(holiday.name);
    else
        puts("not a holiday");

    return r;
}
