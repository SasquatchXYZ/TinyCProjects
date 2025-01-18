#include <stdio.h>
#include <time.h>

int main()
{
    // Presets the `time_t` value to zero,
    // the dawn of the Unix epoch
    time_t epoch = 0;

    // Outputs the time string for the epoch
    printf("Time is %s\n", ctime(&epoch));

    return 0;
}
