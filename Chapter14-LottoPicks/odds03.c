#include <stdio.h>
#include <_stdlib.h>

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
    printf("\t1:%.0f\n", (float)i / (float)d);

    return 0;
}
