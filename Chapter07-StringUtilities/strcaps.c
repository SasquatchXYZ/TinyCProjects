#include <ctype.h>
#include <stdio.h>

void strcaps(char* s)
{
    enum { FALSE, TRUE };
    int inword = FALSE;

    while (*s)
    {
        if (isalpha(*s))
        {
            if (!inword)
            {
                *s = (char)toupper(*s);
                inword = TRUE;
            }
        }
        else
        {
            inword = FALSE;
        }
        s++;
    }
}

int main()
{
    const char string[] = "this is a sample string.";

    printf("Original string: %s\n", string);
    strcaps(string);
    printf("Uppercase string: %s\n", string);

    return 0;
}
