#include <stdio.h>

int main()
{
    const int mdays = 31;
    const int today = 27;
    const int first = 3;

    printf("December 2021\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int day = 1;
    while (day <= mdays)
    {
        for (int d = 0; d < 7; d++)
        {
            if (d < first && day == 1)
            {
                printf("    ");
            }
            else
            {
                if (day == today)
                    printf("[%2d]", day);
                else
                    printf(" %2d ", day);

                day++;

                if (day > mdays)
                    break;
            }
        }
        putchar('\n');
    }

    return 0;
}
