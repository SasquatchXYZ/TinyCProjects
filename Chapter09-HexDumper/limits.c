#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Char:\n");
    printf("\tNumber of Bits: %d\n", CHAR_BIT);
    printf("\tSigned Minimum: %d\n", SCHAR_MIN);
    printf("\tSigned Minimum: %d\n", SCHAR_MAX);
    printf("\tUnsigned Max: %d\n", UCHAR_MAX);

    printf("Short:\n");
    printf("\tSigned Minimum: %d\n", SHRT_MIN);
    printf("\tSigned Minimum: %d\n", SHRT_MAX);
    printf("\tUnsigned Max: %d\n", USHRT_MAX);

    printf("Int:\n");
    printf("\tSigned Minimum: %d\n", INT_MIN);
    printf("\tSigned Minimum: %d\n", INT_MAX);
    printf("\tUnsigned Max: %u\n", UINT_MAX);

    printf("Long:\n");
    printf("\tSigned Minimum: %ld\n", LONG_MIN);
    printf("\tSigned Minimum: %ld\n", LONG_MAX);
    printf("\tUnsigned Max: %lu\n", ULONG_MAX);

    printf("Long long:\n");
    printf("\tSigned Minimum: %lld\n", LLONG_MIN);
    printf("\tSigned Minimum: %lld\n", LLONG_MAX);
    printf("\tUnsigned Max: %llu\n", ULLONG_MAX);

    return 0;
}
