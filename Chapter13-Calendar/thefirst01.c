#include <stdio.h>
#include <time.h>

int main()
{
    const char* weekday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    time_t now;
    time(&now);

    const struct tm* date = localtime(&now);

    const int first = date->tm_wday - date->tm_mday % 7 + 1;

    printf("The first of this month was on a %s\n", weekday[first]);

    return 0;
}
