#include <ctype.h>
#include <stdio.h>

int main()
{
    char* nato[] = {
        "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
        "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
        "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
        "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
        "Xray", "Yankee", "Zulu"
    };
    char ch;

    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
            printf("%s ", nato[toupper(ch) - 'A']); // Translates a character into an offset within the `nato[]` array

        if (ch == '\n') // Outputs a newline when encountered to keep the output clean
            putchar(ch);
    }
    putchar('\n');

    return 0;
}
