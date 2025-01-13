#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    const int r = rand() % 2;

    if (r)
    {
        fprintf(stderr, "Welp, this program is screwed [CA]up!\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("Everything went ducky!\n");
        return EXIT_SUCCESS;
    }
}
