#include <stdio.h>
#include <string.h> // Needed for strlen()

int main()
{
    struct str
    {
        char* string;
        unsigned long (*length)(const char*); // The function member of structure `str`
    };

    struct str str1; // Declare a structure variable
    char s[] = "Heresy";

    str1.string = s; // Assign a string to the structure variable
    str1.length = &strlen; // The function is assigned, no parentheses, and prefixed by the address-of operator.

    printf("The string '%s' is %lu characters long\n",
           str1.string,
           str1.length(str1.string)); // Function is called here in the `printf()` statement

    return 0;
}
