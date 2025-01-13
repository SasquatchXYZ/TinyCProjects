#include <stdio.h>

int main()
{
    const char* month[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    const char* day_of_week[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    const int month_day_count[] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    enum { SU, MO, TU, WE, TH, FR, SA };

    const int start_day = WE;
    int day_of_year = 1;
    for (int m = 0; m < 12; m++)
    {
        for (int day_of_month = 1; day_of_month <= month_day_count[m]; day_of_month++)
        {
            const int year = 2025;
            printf("%s, %s %d, %d\n",
                   day_of_week[(day_of_year + start_day - 1) % 7],
                   month[m],
                   day_of_month,
                   year
            );
            day_of_year++;
        }
    }

    return 0;
}
