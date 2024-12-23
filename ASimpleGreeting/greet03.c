#include <stdio.h>
#include <time.h>

int main(const int argc, char* argv[])
{
    time_t now;

    time(&now);
    const struct tm* clock = localtime(&now);
    const int hour = clock->tm_hour;

    printf("Good ");
    if (hour < 12)
        printf("morning");
    else if (hour < 17)
        printf("afternoon");
    else
        printf("evening");

    if (argc > 1)
        printf(", %s", argv[1]);

    putchar('\n');

    return 0;
}
