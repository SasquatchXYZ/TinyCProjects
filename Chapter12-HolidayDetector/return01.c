#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char* argv[])
{
    // If a command-line argument is present,
    // tries to convert it into an integer
    if (argc > 1)
    {
        // Returns the conversion of string `argv[1]` into
        // an integer (long) value
        return (strtol(argv[1], NULL, 10));
    }
    else
    {
        // When no argument is preset, returns a zero
        exit(0);
    }
}
