#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a macro for the for loop
#define repeat(a) for (int i = 0; i < a; i++)

const char* add_noun(void)
{
    const char* vocabulary[] = {
        "orange", "grape", "apple", "banana",
        "pear", "lemon", "lime", "cherry",
        "strawberry", "watermelon", "mango", "pineapple",
        "peach", "coffee", "tea", "juice", "beverage",
        "happy", "grumpy", "bashful", "sleepy", "doc",
        "dog", "cat", "mouse", "rabbit", "duck",
        "horse", "cow", "sheep", "goat", "chicken",
        "pig", "duck", "turtle", "snake", "fish",
        "elephant", "lion", "tiger", "bear", "fox",
        "deer"
    };

    int r = rand() % (sizeof(vocabulary) / sizeof(char*));
    return vocabulary[r];
}

const char* add_adjective(void)
{
    const char* vocabulary[] = {
        "loud", "big", "soft", "crunchy",
        "smelly", "great", "blue", "tiny",
        "ripe", "hairy"
    };

    int r = rand() % (sizeof(vocabulary) / sizeof(char*));
    return vocabulary[r];
}

const char* add_verb(void)
{
    const char* vocabulary[] = {
        "run", "eat", "burp", "sneeze",
        "cut", "yodel", "cook", "drink",
        "jump", "sleep", "bite", "chase",
        "fly", "swim"
    };

    int r = rand() % (sizeof(vocabulary) / sizeof(char*));
    return vocabulary[r];
}

int main()
{
    srand(time(NULL));

    printf("Will you please take the %s %s ",
           add_adjective(),
           add_noun()
    );

    printf("and %s the %s?\n",
           add_verb(),
           add_noun()
    );

    return 0;
}
