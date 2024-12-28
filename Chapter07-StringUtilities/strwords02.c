#include <ctype.h>
#include <stdio.h>

int strwordcount(char* s)
{
    enum { FALSE, TRUE };
    int inword = FALSE;
    int count = 0;

    while (*s)
    {
        // If we encounter a space...
        if (isspace(*s))
        {
            // ...and we were IN a word...
            if (inword)
            {
                // increase the word count
                count++;
                // now we are no longer in a word
                inword = FALSE;
            }
        }
        else
        {
            // We are still in a word
            inword = TRUE;
        }
        s++;
    }

    // If we are still in a word at the end then count it
    if (inword == TRUE)
        count++;

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
