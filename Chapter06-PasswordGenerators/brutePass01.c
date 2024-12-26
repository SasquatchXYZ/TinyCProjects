#include <stdio.h>
#include <time.h>

int flip(char* c, const int pos)
{
    // Increment the letter
    *(c + pos) = *(c + pos) + 1;
    // Check for overflow
    if (*(c + pos) > 'z')
    {
        // Reset back to `a`
        *(c + pos) = 'a';

        // Check for overflow
        if (pos != 0)
        {
            // Flip the next column's digit
            if (!flip(c, pos - 1))
                return 0;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    const clock_t start = clock();
    // Password we are guessing
    const char password[] = "password";
    // Guess we are making
    char guess[] = "aaaaaaaa";

    printf("Cracking password...\n");

    do
    {
        char* p = password;
        char* g = guess;
        while (*p)
        {
            // Compare each letter
            if (*p == *g)
            {
                p++;
                g++;
            }
            else
            {
                // Break if they don't match
                break;
            }
        }

        // If we've reached the end of the password, we've found the password
        if (*p == '\0' && *g == '\0')
        {
            const clock_t end = clock();
            const double elapsed_seconds = (double)(end - start) / CLOCKS_PER_SEC;
            const double minutes_spent = elapsed_seconds / 60;
            printf("Time spent: %.2f minutes\n", minutes_spent);
            printf("Found password '%s'\n", guess);
            // Break out of the loop
            break;
        }
    }
    while (flip(guess, 7));

    return 0;
}
