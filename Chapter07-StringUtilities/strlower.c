#include <stdio.h>

void strlower(char* s)
{
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z')
        {
            *s += 32;
        }
        s++;
    }
}

int main()
{
    const char string[] = "RANDOM STRING sAmPlE 123@#$";

    printf("Original string: %s\n", string);
    strlower(string);
    printf("Lowercase string: %s\n", string);

    return 0;
}
