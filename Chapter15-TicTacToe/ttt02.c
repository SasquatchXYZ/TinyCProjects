#include <stdio.h>

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

int prompt(const int ply)
{
    printf("%c's turn: Pick a square, 0 to quit: ",
           ply % 2 ? 'O' : 'X'
    );
    int square;
    scanf("%d", &square);
    if (square < 0 || square > 9)
        return 0;
    return square;
}

int main()
{
    int grid[] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
    };

    puts("Tic-Tac-Toe");

    int ply = 0;
    while (1)
    {
        show_grid(grid);
        const int p = prompt(ply);
        if (p == 0)
            break;
        grid[p - 1] = ply % 2 ? -1 : 1;
        ply++;
    }

    return 0;
}
