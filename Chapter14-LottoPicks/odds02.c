#include <stdio.h>

int main()
{
    int items, draw;

    printf("Number of items: ");
    scanf("%d", &items);
    printf("Items to draw: ");
    scanf("%d", &draw);

    unsigned long i = items;
    unsigned long d = draw;
    for (int x = 1; x < draw; x++)
    {
        i *= items - x;
        d *= draw - x;
    }

    printf("Your odds of drawing %d ", draw);
    printf("items from %d are:\n", items);
    printf("\t1:%.0f\n", (float)i / (float)d);

    return 0;
}
