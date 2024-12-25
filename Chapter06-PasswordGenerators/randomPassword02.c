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
    int x;

    srand(time(NULL));

    for (x = 0; x < UPPER; x++)
        putchar(uppercase());
    for (x = 0; x < LOWER; x++)
        putchar(lowercase());
    for (x = 0; x < NUM; x++)
        putchar(number());
    for (x = 0; x < SYM; x++)
        putchar(symbol());

    putchar('\n');

    return 0;
}
