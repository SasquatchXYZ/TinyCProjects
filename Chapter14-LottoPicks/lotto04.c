#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int balls = 69, draw = 5;
    int numbers[balls];

    srand(time(NULL));

    printf("Drawing %d numbers from %d lottery balls:\n",
           draw,
           balls
    );

    int x;
    for (x = 0; x < balls; x++)
    {
        numbers[x] = 0;
    }

    int r;
    for (x = 0; x < draw; x++)
    {
        do
            r = rand() % balls;
        while (numbers[r] == 1);
        numbers[r] = 1;
    }

    int count = 0;
    for (x = 0; x < balls; x++)
    {
        if (numbers[x])
        {
            printf(" %2d", x + 1);
            count++;
            if (count < draw)
                printf(" -");
        }
    }
    putchar('\n');

    return 0;
}
