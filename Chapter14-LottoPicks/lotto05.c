#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 69
#define DRAW 5

// The array is referenced as a pointer in this function
void lotto(int* a)
{
    // This array is local to the function
    int numbers[BALLS];

    int x;
    // Initialize the local array
    for (x = 0; x < BALLS; x++)
    {
        numbers[x] = 0;
    }

    int r;
    for (x = 0; x < DRAW; x++)
    {
        do
            r = rand() % BALLS;
        while (numbers[r] == 1);
        numbers[r] = 1;
    }

    int y = 0; // Serves as the index to the passed array
    for (x = 0; x < BALLS; x++)
    {
        if (numbers[x])
        {
            *(a + y) = x;
            y++;
            if (y == DRAW)
                break;
        }
    }
}

int main()
{
    int match[DRAW];

    srand(time(NULL));

    printf("Trying to match:");
    lotto(match);
    for (int x = 0; x < DRAW; x++)
    {
        printf(" %d", match[x] + 1);
        if (x < DRAW - 1)
            printf(" -");
    }
    putchar('\n');

    return 0;
}
