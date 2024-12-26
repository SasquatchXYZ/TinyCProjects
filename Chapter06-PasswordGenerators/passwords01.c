#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* add_word(void)
{
    const char* vocabulary[] = {
        "Orange", "Grape", "Apple", "Banana",
        "peAr", "leMon", "liMe", "cHerry",
        "straWberry", "watErmelon", "maNgo", "pineaPple",
        "peach", "cOffee", "tea", "juIce", "beveraGe",
        "happY", "gRumpy", "bashFul", "sLeepy", "dOc",
        "dog", "caT", "mouSe", "rabbIt", "dUck",
        "hoRse", "coW", "shEep", "gOat", "cHicken",
        "piG", "duCk", "tuRtle", "snAke", "fiSh",
        "elepHant", "liOn", "tiGer", "beAr", "fOx",
        "deEr"
    };

    int r = rand() % 12;
    return vocabulary[r];
}

const char* number(void)
{
    // The static array's contents are retained when the function terminates.
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

    srand(time(NULL));

    // Initializes the string so that the `strcpy()` function doesn't get upset
    password[0] = '\0';

    strcpy(password, add_word());
    strcat(password, number());
    strcat(password, add_word());
    strcat(password, symbol());
    strcat(password, add_word());

    printf("%s\n", password);

    return 0;
}
