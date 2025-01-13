#include <stdio.h>
#include <time.h>

int main()
{
    // Obtains the number of seconds elapsed since January 1, 1970 - the Unix epoch
    const time_t now = time(NULL);

    // Converts the number of seconds to a `struct tm`
    const struct tm* today = localtime(&now);

    // The `tm_mon` member starts with 0 for January
    const int month = today->tm_mon + 1;

    const int day = today->tm_mday;
    const int weekday = today->tm_wday;

    // The `tm_year` member starts with 1901
    const int year = today->tm_year + 1900;

    printf("Today is %d, %d %d, %d\n",
           weekday,
           month,
           day,
           year);

    return 0;
}
