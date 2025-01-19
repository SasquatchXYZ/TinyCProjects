#include <stdio.h>

int main()
{
    int winning_odds;
    int losing_odds;

    printf("Chances of happening: ");
    scanf("%d", &winning_odds);
    printf("Chances of not happening: ");
    scanf("%d", &losing_odds);

    printf("Your odds of winning are %2.1f%%, or %d:%d\n",
           (float)winning_odds / (float)(winning_odds + losing_odds) * 100,
           winning_odds,
           losing_odds
    );

    return 0;
}
