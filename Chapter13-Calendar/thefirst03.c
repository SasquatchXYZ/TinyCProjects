#include <stdio.h>
#include <time.h>

int the_first(const int wday, const int mday)
{
    int first = wday - (mday % 7) + 1;
    if (first < 0)
        first += 7;

    return first;
}

int main()
{
    enum
    {
        SUNDAY, MONDAY, TUESDAY, WEDNESDAY,
        THURSDAY, FRIDAY, SATURDAY
    };

    const char* weekday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    time_t now;
    time(&now);

    const struct tm* date = localtime(&now);

    printf("If day %d is a %s, the first of the month is on a %s\n",
           date->tm_mday,
           weekday[date->tm_wday],
           weekday[the_first(date->tm_wday, date->tm_mday)]
    );

    return 0;
}
