#include <stdio.h>

int main()
{
    char sentence[] = "ASCII makes my heard beat faster\n";
    char* s;

    s = sentence;
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z') // Filters out uppercase text
            putchar(*s | 0x20); // Outputs the lowercase character
        else
            putchar(*s);
        s++;
    }
    s = sentence;
    while (*s)
    {
        if (*s >= 'a' && *s <= 'z') // Filters out lowercase text
            putchar(*s & 0xdf); // outputs the uppercase character
        else
            putchar(*s);
        s++;
    }

    return 0;
}
