#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Runs the `return01` program and sets a return value of 99
    const int r = system("./return01 99");
    // Reports the value returned by the `system()` function
    printf("The return value is %d\n", r);

    return r;
}
