#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long cc_number, digitcount, i, secondsum, prodsum, digitssum, mastercard, amex, visa;
int digits;


int main(void)
{

// get input from user
    do
    {
        cc_number = get_long_long("Enter your Credit Card number: ");
    }

// if the input is not bigger than 0 it will continue asking for input
    while (cc_number <= 0);

// If the count of digits is lower than 13 or higher than 16, the number entered is not valid
    digitcount = cc_number;

    while (digitcount != 0)
    {
        digitcount /= 10;
        ++digits;
    }

    if (digits > 16 || digits < 13)
    {
        printf("INVALID\n");
    }
    else
    {

// Implement the checksum validation

        // sum of the numbers not multiplied by 2

        for (i = cc_number; i > 0; i /= 100)
        {
            secondsum += i % 10;
        }

        // Multiply every other digit by 2, starting with the number's second-to-last digit, and then add those products' digits together.

        for (i = cc_number / 10; i > 0; i /= 100)
        {
            prodsum = (i % 10);
            digitssum += (prodsum * 2) % 10 + (prodsum * 2) / 10;
        }

        if ((secondsum + digitssum) % 10 == 0)
        {


// here we will define the company of the card based on the digits of the card number

            // VISA validation for numbers of 13 digits

            if (digits == 13 && cc_number / 100000000000 == 4)
            {
                printf("VISA\n");
            }

            // AMEX validation for numbers of 15 digits

            else if (digits == 15)
            {
                amex = (cc_number / 10000000000000);
//                printf("%lld \n", amex);
                if (amex == 34 || amex == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }

            // MASTERCARD and VISA validation for numbers of 16 digits

            else if (digits == 16)
            {
                mastercard = (cc_number / 100000000000000);
                if (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (cc_number / 1000000000000000 == 4)
                {

                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}