#include <stdio.h>
#include <cs50.h>
#include <math.h>

float n;
int change;
int counter = 0;
int amount;

int main(void)
{

    // get input from user
    do
    {
        n = get_float("Enter the change: ");
    }

    // if the input is not bigger than 0 it will continue asking for input
    while (n <= 0);

    // formatting the amount entered by the user and assign it to the integer "change" variable
    change = (int)((n * 100) < 0 ? ((n * 100) - 0.5) : ((n * 100) + 0.5));

    // Loop for quarter coins
    while (change >= 25)
    {
        counter ++;
        change -= 25;
    }
    // Loop for dime coins
    while (change >= 10)
    {
        counter ++;
        change -= 10;
    }
    // Loop for nickel coins
    while (change >= 5)
    {
        counter ++;
        change -= 5;
    }
    // Loop for cent coins
    while (change >= 1)
    {
        counter ++;
        change -= 1;
    }
// print the number of coins used
    printf("%i \n", counter);

}