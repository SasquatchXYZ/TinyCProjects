#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int rows = 5;

    srand(time(NULL));

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            int r = rand() % 100 + 1;
            printf("%3d ", r);
        }
        putchar('\n');
    }

    return 0;
}
