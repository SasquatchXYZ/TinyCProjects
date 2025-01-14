#include <stdio.h>
#include <time.h>

int main()
{
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    time_t now;

    // Obtain the current time in clock ticks
    time(&now);
    // Convert the clock ticks to a struct tm
    const struct tm* date = localtime(&now);

    // Set local variables for convenience and readability
    const int day = date->tm_mday;
    const int month = date->tm_mon;
    const int weekday = date->tm_wday;
    // Calculate the date for Sunday
    const int sunday = day - weekday;

    printf("  %s\n", months[month]);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int d = sunday; d < sunday + 7; d++)
    {
        if (d == day)
            printf("[%2d]", d);
        else
            printf(" %2d ", d);
    }
    putchar('\n');

    return 0;
}
