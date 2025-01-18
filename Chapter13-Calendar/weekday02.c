#include <stdio.h>

int day_of_the_week(const int m, const int d, int y)
{
    int t[] = {
        0, 3, 2, 5, 0, 3,
        5, 1, 4, 5, 2, 4
    };

    y -= m < 2;
    const int r = (y + y / 4 - y / 100 + y / 400 + t[m] + d) % 7;
    return r;
}

int main()
{
    const char* weekday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    const char* month[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    const int m = 1;
    const int d = 3;
    const int y = 1993;

    const int r = day_of_the_week(m, d, y);

    printf("%s %d, %d is a %s\n",
           month[m],
           d,
           y,
           weekday[r]
    );

    return 0;
}
