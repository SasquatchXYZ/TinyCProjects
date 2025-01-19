#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    const int balls = 69, draw = 5;
    int winners[draw];

    srand(time(NULL));

    printf("Drawing %d numbers from %d lottery balls:\n",
           draw,
           balls
    );

    int x;
    for (x = 0; x < draw; x++)
    {
        winners[x] = rand() % balls + 1;
    }

    for (x = 0; x < draw - 1; x++)
        for (int y = x + 1; y < draw; y++)
            if (winners[x] == winners[y])
            {
                winners[y] = rand() % balls + 1;
                y = draw;
                x = -1;
            }

    qsort(winners, draw, sizeof(int), compare);

    for (x = 0; x < draw; x++)
    {
        printf(" %2d", winners[x]);
        if (x < draw - 1)
            printf(" -");
    }

    return 0;
}
