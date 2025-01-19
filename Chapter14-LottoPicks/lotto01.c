#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int balls = 69, draw = 5;
    srand(time(NULL));

    printf("Drawing %d numbers from %d lottery balls:\n",
           draw,
           balls
    );

    for (int x = 0; x < draw; x++)
    {
        int r = rand() % balls + 1;
        printf("%2d\n", r);
    }

    return 0;
}
