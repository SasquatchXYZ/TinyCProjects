#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* add_commas(const float num)
{
    const int size = 128;
    char string[size];
    static char comma_string[size];

    snprintf(string, size, "%.0f", num);
    int len = strlen(string);
    int s = 0;
    int c = 0;

    if (num < 1)
    {
        strcpy(comma_string, "0");
        return comma_string;
    }

    if (num < 1000)
    {
        strcpy(comma_string, string);
        return comma_string;
    }

    while (string[s])
    {
        if (len % 3 == 0 && c > 0)
        {
            comma_string[c] = ',';
            c++;
        }
        comma_string[c++] = string[s++];
        len--;
    }

    return comma_string;
}

int main()
{
    int items, draw;

    printf("Number of items: ");
    scanf("%d", &items);
    printf("Items to draw: ");
    scanf("%d", &draw);

    if (items < 0 || draw < 0)
    {
        fprintf(stderr, "Enter amounts greater than zero\n");
        return EXIT_FAILURE;
    }

    if (draw > items)
    {
        fprintf(stderr, "Draw cannot be greater than the number of items\n");
        return EXIT_FAILURE;
    }

    unsigned long i = items;
    unsigned long d = draw;
    for (int x = 1; x < draw; x++)
    {
        i *= items - x;
        d *= draw - x;
    }

    printf("Your odds of drawing %d ", draw);
    printf("items from %d are:\n", items);
    printf("\t1:%s\n", add_commas((float)i / (float)d));

    return 0;
}
