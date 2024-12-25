#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char uppercase(void)
{
    return rand() % 26 + 'A';
}

char lowercase(void)
{
    char ch = uppercase();
    return ch |= 0x20;
}

char number(void)
{
    return rand() % 10 + '0';
}

char symbol(void)
{
    const char symbols[] = "!@#$%^&*_-";
    const int r = rand() % (sizeof(symbols) - 1);
    return symbols[r];
}

void scramble(char array[])
{
    const int size = UPPER + LOWER + NUM + SYM + 1;
    char key[size];
    int x;

    for (x = 0; x < size; x++)
        key[x] = '\0';

    x = 0;
    while (x < size - 1)
    {
        const int r = rand() % (size - 1);
        if (!key[r])
        {
            key[r] = array[x];
            x++;
        }
    }

    for (x = 0; x < size; x++)
        array[x] = key[x];
}

int main()
{
    char password[UPPER + LOWER + NUM + SYM + 1]; // +1 for '\0'

    // Seeds the random number generator
    srand(time(NULL));

    int x = 0;
    while (x < UPPER)
        password[x++] = uppercase();
    while (x < UPPER + LOWER)
        password[x++] = lowercase();
    while (x < UPPER + LOWER + NUM)
        password[x++] = number();
    while (x < UPPER + LOWER + NUM + SYM)
        password[x++] = symbol();

    password[x] = '\0';

    scramble(password);

    printf("%s\n", password);

    return 0;
}
