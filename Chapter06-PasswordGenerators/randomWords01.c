#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a macro for the for loop
#define repeat(a) for (int i = 0; i < a; i++)

const char* add_word(void)
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

int main()
{
    srand(time(NULL));

    repeat(3)
        printf("%s ", add_word());
    putchar('\n');

    return 0;
}
