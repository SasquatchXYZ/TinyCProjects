#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int rows = 5;
    int r;

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            r = rand();
            printf("%d ", r);
        }
        putchar('\n');
    }

    return 0;
}
