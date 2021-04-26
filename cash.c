#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int coins = 0;
    // prompt user for change
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);
    // changing dollars to cents
    int cents = round(change * 100);
    // checking value of change and updating it each iteration and increasing number of coins
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
        coins++;
    }
    // printing number of coins
    printf("%i", coins);
}