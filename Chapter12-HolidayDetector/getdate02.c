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

    // Obtains the number of seconds elapsed since January 1, 1970 - the Unix epoch
    const time_t now = time(NULL);

    // Converts the number of seconds to a `struct tm`
    const struct tm* today = localtime(&now);

    // The `tm_mon` member starts with 0 for January
    const int month = today->tm_mon;

    const int day = today->tm_mday;
    const int weekday = today->tm_wday;

    // The `tm_year` member starts with 1901
    const int year = today->tm_year + 1900;

    printf("Today is %s, %s %d, %d\n",
           days_of_the_week[weekday],
           months[month],
           day,
           year);

    return 0;
}
