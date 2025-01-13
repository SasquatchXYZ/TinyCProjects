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
    // 0 is January, and we want April: so writing it as 4 - 1
    day.tm_mon = 4 - 1;
    day.tm_mday = 12;
    // This format makes it clear which year we actually want - 2022
    day.tm_year = 2022 - 1900;

    mktime(&day);

    printf("%02d/%02d/%04d is on a %s\n",
           day.tm_mon + 1,
           day.tm_mday,
           day.tm_year + 1900,
           days_of_the_week[day.tm_wday]
    );

    return 0;
}
