#include <stdio.h>

int main()
{
    int a, b;

    printf("Type a letter:");
    a = getchar();
    printf("Type another letter:");
    b = getchar();

    printf("a = '%c', b = '%c'\n", a, b);

    return 0;
}
