#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char cwd[BUFSIZ];

    // Changes to the parent directory
    const int r = chdir("..");
    if (r == -1)
    {
        fprintf(stderr, "Unable to change directories\n");
        exit(1);
    }

    // Obtain the parent directory's path
    getcwd(cwd, BUFSIZ);
    // Output the parent directory's path
    printf("The current working directory is %s\n", cwd);

    return 0;
}
