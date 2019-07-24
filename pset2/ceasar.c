#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Ensure that command line argument './caesar key' was received
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
                    // If character is upper case (ASCII 65 to 90)
                    if (plaintext[j] >= 65 && plaintext[j] <= 90)
                    {
                        if (plaintext[j] + key > 90)
                        {
                            plaintext[j] = 65 + ((key  - 1 - (90 - plaintext[j])) % 26);
                        } 
                        else 
                        {
                            plaintext[j] += key;
                        }
                    }
                    
                    //If character is lower case (ASCII 97 to 122)
                    if (plaintext[j] >= 97 && plaintext[j] <= 122)
                    {
                        if (plaintext[j] + key > 122)
                        {
                            plaintext[j] = 97 + ((key - 1 - (122 - plaintext[j])) % 26);
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