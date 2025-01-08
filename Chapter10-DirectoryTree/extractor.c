#include <stdio.h>
#include <string.h>

const char* extract(const char* path)
{
    const int len = strlen(path);

    // If the string is empty we return NULL
    if (len == 0)
        return NULL;

    // Special case to test for the root directory
    if (len == 1 & *(path + 0) == '/')
        return path;

    // Positions pointer `p` at the end of the string `path`
    const char* p = path + len;

    // Move backwards until we find a `/` separator
    while (*p != '/')
    {
        p--;
        // If we back up too far, return NULL
        if (p == path)
            return NULL;
    }

    // Increments `p` over the separator character
    p++;

    // Tests to see if the string is empty or malformed and returns NULL
    if (*p == '\0')
        return NULL;

    // Returns the address where the final directory name starts
    return p;
}

int main()
{
    const int count = 4;
    const char* pathname[count] = {
        "/home/sasquatchxyz",
        "/usr/local/this/that",
        "/",
        "nothing here"
    };

    for (int x = 0; x < count; x++)
    {
        printf("%s -> %s\n",
               pathname[x],
               extract(pathname[x]));
    }

    return 0;
}
