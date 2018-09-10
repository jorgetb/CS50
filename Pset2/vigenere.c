#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Vignere cipher. It requires a command line input for the key, will prompt for the plain text and will return the ciphered text based on the Vignere algorithm.


int main(int argc, string argv[])
{
    if (argc !=
        2)                                                              // Checking if there are not 2 arguments and Exit if true
    {
        printf("Please, enter two arguments, program name and key.\n");
        return 1;
    }

    string key =
        argv[1];                                                        // Assign to the variable key the string entered as Key when running the program

    int j = 0;
    int length = strlen(key);


    for (int x = 0; x < strlen(key);
         x++)                                                           // For loop to identify if there is any character non-alphabetic in the key entered and Exit if true
    {
        if (isalpha(key[x]))
        {
            ;
        }
        else
        {
            printf("Please, enter an alphabetic key.\n");
            return 1;
        }
    }

    string plain_text = get_string("Enter the string to be ciphered: ");                    // Prompt for the plaintext

    printf("ciphertext: ");                                                                 // Print the start of the sentence before the cipher loop

    for (int i = 0; i < strlen(plain_text); i++)                                            // For each character in the plain text
    {
        if (isalpha(plain_text[i]))                                                         // if it is alphabetic
        {
            if (islower(plain_text[i]))                                                     // if it is lowercase the plaintext character
            {
                if (islower(key[j]))                                                        // if it is lowercase the key character
                {
                    printf("%c", (((plain_text[i] + (key[j] - 97) - 97) % 26) +
                                  97));                                                     // Apply the key and create the alphabetical index for both lowercase
                }
                else
                {
                    printf("%c", (((plain_text[i] + (key[j] - 97) - 65) % 26) +
                                  97));                                                    // Apply the key and create the alphabetical index for lowercase and key uppercase
                }
            }
            else if (isupper(plain_text[i]))                                                // if it is lowercase the plaintext character
            {
                if (islower(key[j]))                                                        // if it is lowercase the key character
                {
                    printf("%c", (((plain_text[i] + (key[j] - 97) - 97) % 26) +
                                  97));                                                     // Apply the key and create the alphabetical index for uppercase and key lowercase
                }
                else
                {
                    printf("%c", (((plain_text[i] + (key[j] - 65) - 65) % 26) +
                                  65));                                                     // Apply the key and create the alphabetical index for both uppercase
                }
            }
            j++;                                                                            // Increase variable j by 1
            j = j % length;                                                                 // Apply the modulo to j to wrap around the length of the key
        }
        else
        {
            printf("%c", plain_text[i]);                                        // If it is not alphabetic we just maintain the same character
        }
    }
    printf("\n");                                                               // Print a new line at the end of the run
}

