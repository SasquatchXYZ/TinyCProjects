#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TL *(grid + 0)
#define TC *(grid + 1)
#define TR *(grid + 2)
#define ML *(grid + 3)
#define MC *(grid + 4)
#define MR *(grid + 5)
#define BL *(grid + 6)
#define BC *(grid + 7)
#define BR *(grid + 8)

void show_grid(const int* g)
{
    const char bfwb[] = "\x1b[32;47m";
    const char bf[] = "\x1b[32m";
    const char xfwb[] = "\x1b[31;47m";
    const char xf[] = "\x1b[31m";
    const char ofwb[] = "\x1b[34;47m";
    const char of[] = "\x1b[34m";
    const char reset[] = "\x1b[0m";

    for (int x = 0; x < 9; x++)
    {
        switch (*(g + x))
        {
        case -1:
            if (x % 2)
                printf("%s O %s", ofwb, reset);
            else
                printf("%s O %s", of, reset);
            break;
        case 1:
            if (x % 2)
                printf("%s X %s", xfwb, reset);
            else
                printf("%s X %s", xf, reset);
            break;
        default:
            if (x % 2)
                printf("%s %d %s", bfwb, x + 1, reset);
            else
                printf("%s %d %s", bf, x + 1, reset);
            break;
        }

        if ((x + 1) % 3 == 0)
            putchar('\n');
    }
    putchar('\n');
}

int winner(const int* grid)
{
    int slice[8];
    slice[0] = TL + ML + BL; // Left Column
    slice[1] = TC + MC + BC; // Middle Column
    slice[2] = TR + MR + BR; // Right Column
    slice[3] = TL + TC + TR; // Top Row
    slice[4] = ML + MC + MR; // Middle Row
    slice[5] = BL + BC + BR; // Bottom Row
    slice[6] = TL + MC + BR; // Top Left to Bottom Right
    slice[7] = TR + MC + BL; // Top Right to Bottom Left

    for (int i = 0; i < 8; i++)
    {
        if (slice[i] == -3)
        {
            show_grid(grid);
            puts(">>> O Wins! <<<");
            return 1;
        }

        if (slice[i] == 3)
        {
            show_grid(grid);
            puts(">>> X Wins! <<<");
            return 1;
        }
    }

    return 0;
}

int prompt(const int ply, const int* grid)
{
    int square;

    printf("%c's turn: Pick a square, 0 to quit: ",
           ply % 2 ? 'O' : 'X'
    );
    scanf("%d", &square);

    if (square < 0 || square > 9)
    {
        puts("Value out of range");
        return -1; // -1 for invalid input
    }

    // If 0 then return to quit the game
    if (square == 0)
        return square;

    if (*(grid + square - 1) != 0)
    {
        printf("Square %d is occupied, try again\n",
               square
        );
        return -1; // -1 for invalid input
    }

    // Returns the unoccupied, chosen square
    return square;
}

int computer(const int* grid)
{
    int r;

    do
    {
        r = rand() % 9;
    }
    while (*(grid + r) != 0);

    r++;
    printf("The computer picked square %d\n", r);

    return r;
}

int main()
{
    int grid[] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
    };

    srand(time(NULL));

    puts("Tic-Tac-Toe");
    printf("Number of players (0, 1, 2): ");
    const int players;
    scanf("%d", &players);
    if (players < 0 || players > 2)
        return 1;

    int ply = 0;
    int p;
    while (ply < 9)
    {
        show_grid(grid);
        // Computer plays itself
        if (players == 0)
        {
            p = computer(grid);
        }
        else if (players == 1)
        {
            // Computer plays odd turns
            if (ply % 2)
            {
                p = computer(grid);
            }
            else
            {
                while ((p = prompt(ply, grid)) == -1)
                    ;
            }
        }
        else
        {
            while ((p = prompt(ply, grid)) == -1)
                ;
        }

        if (p == 0)
            break;

        grid[p - 1] = ply % 2 ? -1 : 1;

        if (winner(grid))
            break;

        ply++;
    }

    if (ply == 9)
    {
        show_grid(grid);
        puts("--- Cat's Game! ---");
    }

    return 0;
}
