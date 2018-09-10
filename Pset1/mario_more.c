#include <stdio.h>
#include <cs50.h>

int n;

int main(void)
{

    // get input from user
    do
    {
        n = get_int("Enter the heigth: ");
    }

    // if the input is not in the Range from 1 to 23, it will continue asking for input
    while (n > 23 || n < 0);

    // initial loop to execute the code the n times entered by the user (formula for the pyramid: " " * n-1 + "#" * i + "\n")
    for (int i = 0; i < n; i++)
    {

        // loop to print spaces n-1 times
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }

        // loop to print the hash i times
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // print 2 spaces
        {
            printf("  ");
        }

        // loop to print the hash i times
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // print a new line at the end of each initial loop
        printf("\n");
    }
}