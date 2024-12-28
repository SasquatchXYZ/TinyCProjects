#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { FALSE, TRUE };

struct string
{
    char* value;
    int length;
};

int string_create(struct string* s, const char* value)
{
    if (s == NULL) // Confirms that the string is available
        return FALSE;

    s->length = strlen(value);  // Assigns the string length

    s->value = malloc(sizeof(char) * s->length + 1); // Allocates storage for the string

    if (s->value == NULL)
        return FALSE;

    strcpy(s->value, value); // Copies the string to newly allocated storage

    return TRUE;
}

void string_destroy(struct string* s)
{
    free(s->value); // Free string storage memory
     // Reset the string pointer to NULL, which can be used later
     // to test for a valid string structure
    s->value = NULL;
    s->length = 0; // Resets the string length to zero
}

int main()
{
    struct string str1;

    string_create(&str1, "I am not a string object");

    printf("The string '%s' is %d characters long\n",
           str1.value,
           str1.length);

    string_destroy(&str1);

    return 0;
}
