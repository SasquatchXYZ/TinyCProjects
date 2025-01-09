#include <stdio.h>

int main(const int argc, const char* argv[])
{
    if (argc > 1)
    {
        for (int x = 1; x < argc; x++)
            printf("%s\n", argv[x]);
    }

    return 0;
}
