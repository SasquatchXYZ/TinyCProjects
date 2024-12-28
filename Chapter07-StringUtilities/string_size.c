#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "0123456789";

    printf("%s is %lu characters long\n", s, strlen(s));
    printf("%s occupies %zu bytes of storage\n", s, sizeof(s));

    char s2[20] = "0123456789";

    printf("%s is %lu characters long\n", s2, strlen(s2));
    printf("%s occupies %zu bytes of storage\n", s2, sizeof(s2));

    return 0;
}
