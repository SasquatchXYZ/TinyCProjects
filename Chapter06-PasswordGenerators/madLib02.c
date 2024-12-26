#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 32

struct term
{
    char filename[16]; // A string representing the filename to open
    FILE* file; // A FILE pointer referencing the open file listed in the filename member
    int item_count; // The total number of words extracted from the file
    char** list_base; // A block of memory containing pointers referencing each word extracted from the file
};

void build_vocabulary(struct term* t)
{
    t->file = fopen(t->filename, "r");
    if (t->file == NULL)
    {
        printf("Error opening file %s\n", t->filename);
        exit(1);
    }

    // Allocate storage for the `list_base` member
    t->list_base = malloc(sizeof(char*) * 100);
    if (t->list_base == NULL)
    {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    t->item_count = 0;
    while (!feof(t->file))
    {
        char buffer[BSIZE];
        char* r = fgets(buffer, BSIZE, t->file);
        if (r == NULL)
            break;

        // Allocates memory for the string
        char* entry = malloc(sizeof(char) * strlen(buffer) + 1);

        if (entry == NULL)
        {
            fprintf(stderr, "Error allocating memory\n");
            exit(1);
        }

        strcpy(entry, buffer);
        r = entry;

        while (*r)
        {
            // Removes the newline from the string
            if (*r == '\n')
            {
                *r = '\0';
                break;
            }
            r++;
        }

        *(t->list_base + t->item_count) = entry;
        t->item_count++;

        // Confirms that the buffer isn't full...
        if (t->item_count % 100 == 0)
        {
            // If it is... reallocates the buffer to a larger size
            t->list_base = realloc(t->list_base, sizeof(char*) * (t->item_count + 100));
            if (t->list_base == NULL)
            {
                fprintf(stderr, "Error reallocating memory\n");
                exit(1);
            }
        }
    }
    fclose(t->file);
}

char* add_word(const struct term t)
{
    const int word = rand() % t.item_count;
    return *(t.list_base + word);
}

int main()
{
    struct term noun = {"noun.txt", NULL, 0, NULL};
    struct term verb = {"verb.txt", NULL, 0, NULL};
    struct term adjective = {"adjective.txt", NULL, 0, NULL};

    build_vocabulary(&noun);
    build_vocabulary(&verb);
    build_vocabulary(&adjective);

    srand(time(NULL));

    printf("Will you please take the %s %s ",
           add_word(adjective),
           add_word(noun)
    );

    printf("and %s the %s?\n",
           add_word(verb),
           add_word(noun)
    );

    return 0;
}
