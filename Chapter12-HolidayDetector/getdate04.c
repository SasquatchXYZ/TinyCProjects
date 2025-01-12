#include <stdio.h>
#include <time.h>

int main()
{
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    const char* days_of_the_week[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    struct tm day;
    day.tm_mon = 4 - 1;
    day.tm_mday = 12;
    day.tm_year = 2022 - 1900;
    day.tm_hour = 0;
    day.tm_min = 0;
    day.tm_sec = 0;

    mktime(&day);

    printf("%02d/%02d/%04d is on a %s\n",
           day.tm_mon + 1,
           day.tm_mday,
           day.tm_year + 1900,
           days_of_the_week[day.tm_wday]
    );

    return 0;
}
