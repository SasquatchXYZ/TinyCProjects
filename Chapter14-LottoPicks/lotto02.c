#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    for (x = 0; x < draw; x++)
        printf("%2d\n", winners[x]);

    return 0;
}
