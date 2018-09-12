#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

// Crack a password of maximum 5 characters long that has been hashed with C’s DES-based crypt function.
// The hash is provided as argument when running the program.

int main(int argc, string argv[])
{
    if (argc !=
        2)                                                                          // Checking if there are not 2 arguments and Exit if true
    {
        printf("Please, enter two arguments, program name and hash.\n");
        return 1;
    }

    string hash =
        argv[1];                                                          // Assign to the variable hash the string entered as hash
    char salt[3] = {hash[0], hash[1], '\0'};                                        // Taking the salt from the two first characters of the hash
    char pass[6];                                                                   // Initialize the variable that will store the password

//--------------------------------------------------------
// Bruteforce loops
//--------------------------------------------------------

// password of 1 character

    for (int i = 65; i < 123; i++)
    {
        pass[0] = i;
        pass[1] = '\0';
        if (strcmp(crypt(pass, salt), hash) == 0)
        {
            printf("%s\n", pass);
            return true;
        }
    }

// password of 2 characters

    for (int i = 65; i < 123; i++)
    {
        pass[0] = i;
        pass[2] = '\0';
        for (int j = 65; j < 123; j++)
        {
            pass[1] = j;
            if (strcmp(crypt(pass, salt), hash) == 0)
            {
                printf("%s\n", pass);
                return true;
            }
        }

    }

// password of 3 characters

    for (int i = 65; i < 123; i++)
    {
        pass[0] = i;
        pass[3] = '\0';
        for (int j = 65; j < 123; j++)
        {
            pass[1] = j;
            for (int k = 65; k < 123; k++)
            {
                pass[2] = k;
                if (strcmp(crypt(pass, salt), hash) == 0)
                {
                    printf("%s\n", pass);
                    return true;
                }
            }

        }

    }

// password of 4 characters

    for (int i = 65; i < 123; i++)
    {
        pass[0] = i;
        pass[4] = '\0';
        for (int j = 65; j < 123; j++)
        {
            pass[1] = j;
            for (int k = 65; k < 123; k++)
            {
                pass[2] = k;
                for (int l = 65; l < 123; l++)
                {
                    pass[3] = l;
                    if (strcmp(crypt(pass, salt), hash) == 0)
                    {
                        printf("%s\n", pass);
                        return true;
                    }
                }

            }

        }

    }

// password of 5 characters

    for (int i = 65; i < 123; i++)
    {
        pass[0] = i;
        pass[5] = '\0';
        for (int j = 65; j < 123; j++)
        {
            pass[1] = j;
            for (int k = 65; k < 123; k++)
            {
                pass[2] = k;
                for (int l = 65; l < 123; l++)
                {
                    pass[3] = l;
                    for (int m = 65; m < 123; m++)
                    {
                        pass[4] = m;
                        if (strcmp(crypt(pass, salt), hash) == 0)
                        {
                            printf("%s\n", pass);
                            return true;
                        }
                    }

                }

            }

        }

    }
    return 0;
}