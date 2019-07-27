// Implements Ceasars cipher, which encrypts messages by
// shifting each ASCII value of given plaintext by 'key' 
// number of characters.
// Samantha Tripp
// 01/2019

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Ensure that command line argument './caesar key' was received
    const int LETTERS_IN_ALPHABET = 26;
    int key;
    if (argc == 2)
    {
        // Iterate through the string to ensure that key contains only digits
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!(isalnum(argv[1][i])) || isalpha(argv[1][i]))
            {
                printf("Usage : ./caesar key\n");
                break;
            }
            // The provided key contains only digits and is converted to an int
            if (i == (strlen(argv[1]) - 1))
            {
                printf("Success\n");
                key = atoi(argv[1]);
                printf("%i\n", key);
                
                // Prompt user for a plaintext string
                string plaintext = get_string("plaintext: ");
                
                // Convert the plaintext to cyphertext
                // Rotate each ASCII value by 'key' characters
                printf("ciphertext: ");
                for (int j = 0; j < strlen(plaintext); j++)
                {
                    // If character is upper case (ASCII 'A'  to 'Z')
                    if (plaintext[j] >= (int) 'A' && plaintext[j] <= (int) 'Z')
                    {
                        if (plaintext[j] + key > (int) 'Z')
                        {
                            plaintext[j] = (int) 'A' + ((key  - 1 - ((int) 'Z' - plaintext[j])) % LETTERS_IN_ALPHABET);
                        } 
                        else 
                        {
                            plaintext[j] += key;
                        }
                    }
                    
                    //If character is lower case (ASCII 'a'  to 'z')
                    if (plaintext[j] >= (int) 'a' && plaintext[j] <= (int) 'z')
                    {
                        if (plaintext[j] + key > (int) 'z')
                        {
                            plaintext[j] = (int) 'a' + ((key - 1 - ((int) 'z' - plaintext[j])) % LETTERS_IN_ALPHABET);
                        }
                        else 
                        {
                            plaintext[j] += key;
                        }
                    }
                    printf("%c", plaintext[j]);
                }
                printf("\n");
                return 0;
            }
        }
    } 
    else 
    {
        // More than one argument was received 
        printf("Usage : ./caesar key\n");
    }
    return 1;
}