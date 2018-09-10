#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Caesar cipher. It requires a command line input for the key, will prompt for the plain text and will return the ciphered text.

int main(int argc, string argv[])
{
    if (argc != 2)                                                              // Checking if there are not 2 arguments and Exit if true
    {
        printf("Please, enter two arguments, program name and key.\n");
        return 1;
    }

    int key;
    key = atoi(argv[1]);                                                        // Convert the key from string to integer

    if (key < 0)                                                                // Checking if the key is negative and Exit if is true
    {
        printf("Please, enter a positive key.\n");
        return 1;
    }

    string plain_text = get_string("Enter the string to be ciphered: ");        // Prompt for the plaintext


    printf("ciphertext: ");                                                     // Print the start of the sentence before the cipher loop

    for (int i = 0; i < strlen(plain_text); i++)                                // For each character in the plain text
    {
        if (isalpha(plain_text[i]))                                             // If it is alphabetic
        {
            if (islower(plain_text[i]))                                         // Check if it is lowercase
            {
                printf("%c", (((plain_text[i] + key) - 97) % 26) + 97);         // Apply the key and create the alphabetical index for lowercase
            }
            else if (isupper(plain_text[i]))                                    // Check if it is uppercase
            {
                printf("%c", (((plain_text[i] + key) - 65) % 26) + 65);         // Apply the key and create the alphabetical index for uppercase
            }
        }
        else
        {
            printf("%c", plain_text[i]);                                        // If it is not alphabetic we just maintain the same character
        }
    }

    printf("\n");                                                               // Print a new line at the end of the run
}

