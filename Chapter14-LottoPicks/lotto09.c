#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 69
#define DRAW 5

// The array is referenced as a pointer in this function
void lotto(int* a)
{
    int numbers[BALLS];

    int x;
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

int winner(const int* m, const int* g)
{
    int c = 0; // Match count
    for (int x = 0; x < DRAW; x++)
        for (int y = 0; y < DRAW; y++)
        {
            // Compare each element value
            if (*(m + x) == *(g + y))
                c++;
        }

    return c;
}

int main()
{
    const int to_match = 5;
    const int tally = 100;
    int match[DRAW], guess[DRAW];

    srand(time(NULL));

    printf("Trying to match:");
    lotto(match);
    for (int x = 0; x < DRAW; x++)
    {
        printf(" %2d", match[x] + 1);
        if (x < DRAW - 1)
            printf(" -");
    }
    putchar('\n');

    int results[tally];
    int q = 0;
    while (q < tally)
    {
        int count = 0;
        int c;
        do
        {
            lotto(guess);
            c = winner(match, guess);
            count++;
        }
        while (c < to_match);
        results[q] = count;
        q++;
    }

    long total = 0;
    for (int x = 0; x < tally; x++)
        total += results[x];
    const float average = (float)total / (float)tally;

    printf("For %d times, the average count ", tally);
    printf("to match %d balls is %.0f\n", to_match, average);

    return 0;
}
