#include <ctype.h>
#include <stdio.h>

int strwordcount(char* s)
{
    enum { FALSE, TRUE };
    int inword = FALSE;
    int count = 0;

    while (*s)
    {
        if (isalpha(*s))
        {
            if (!inword)
            {
                count++;
                inword = TRUE;
            }
        }
        else
        {
            // For non-alpha characters, `inword` is FALSE.
            inword = FALSE;
        }
        s++;
    }
    return count;
}

int main()
{
    const char s1[] = "this is a sample string.";
    const char s2[] = "this isn't a sample string.";

    printf("The string '%s' contains %d words\n", s1, strwordcount(s1));
    printf("The string '%s' contains %d words\n", s2, strwordcount(s2));

    return 0;
}
