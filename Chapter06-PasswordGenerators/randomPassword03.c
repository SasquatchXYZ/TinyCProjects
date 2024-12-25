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
    const char symbols[] = "!@#$%^&*()_+=-[]{}|;':\",./<>?";
    const int r = rand() % (sizeof(symbols) - 1);
    return symbols[r];
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
    while (x < UPPER + LOWER + SYM)
        password[x++] = symbol();

    password[x] = '\0';

    printf("%s\n", password);

    return 0;
}
