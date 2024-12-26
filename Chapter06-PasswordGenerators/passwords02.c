#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 32

struct term
{
    char filename[16];
    FILE* file;
    int item_count;
    char** list_base;
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

const char* add_word(struct term t)
{
    int word = rand() % t.item_count;
    return *(t.list_base + word);
}

const char* number(void)
{
    static char n[2];

    n[0] = rand() % 10 + '0';
    n[1] = '\0';

    return n;
}

const char* symbol(void)
{
    char sym[8] = "!@#$%*_-";
    static char s[2];

    s[0] = sym[rand() % 8];
    s[1] = '\0';

    return s;
}

int main()
{
    char password[32];
    struct term noun = {"noun.txt", NULL, 0, NULL};
    struct term verb = {"verb.txt", NULL, 0, NULL};
    struct term adjective = {"adjective.txt", NULL, 0, NULL};

    build_vocabulary(&noun);
    build_vocabulary(&verb);
    build_vocabulary(&adjective);

    srand(time(NULL));

    password[0] = '\0';
    strcpy(password, add_word(noun));
    strcat(password, number());
    strcat(password, add_word(verb));
    strcat(password, symbol());
    strcat(password, add_word(adjective));

    printf("%s\n", password);

    return 0;
}
