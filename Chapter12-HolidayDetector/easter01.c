#include <stdio.h>
#include <math.h>

void easter(int year)
{
    const int Y = year;
    const int a = Y % 19;
    const double b = floor(Y / 100);
    const int c = Y % 100;
    const double d = floor(b / 4);
    const int e = (int)b % 4;
    const double f = floor((b + 8) / 25);
    const double g = floor((b - f + 1) / 3);
    const int h = (19 * a + (int)b - (int)d - (int)g + 15) % 30;
    const double i = floor(c / 4);
    const int k = c % 4;
    const int L = (32 + 2 * e + 2 * (int)i - h - k) % 7;
    const double m = floor((a + 11 * h + 22 * L) / 451);
    const double month = floor((h + L - 7 * m + 114) / 31);
    const double day = ((h + L - 7 * (int)m + 114) % 31) + 1;

    printf("In %d, Easter is ", Y);
    if (month == 3)
        printf("March %d\n", (int)day);
    else
        printf("April %d\n", (int)day);
}

int main()
{
    for (int x = 2018; x < 2036; x++)
        easter(x);

    return 0;
}
