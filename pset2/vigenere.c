// Implements Vigenere's cipher, which encrypts messages by
// shifting each ASCII value of given plaintext by a sequence
// of 'key' number of characters, specified by a 'keyword'.
// Samantha Tripp
// 27/07/2019

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    const int LETTERS_IN_ALPHABET = 26;

    // Ensure that command line argument './vigenere keyword' was received
    if (argc == 2)
    {
        // Iterate through the string to ensure that keyword contains only letters
        for (int i = 0, length = strlen(argv[1]); i < length ; i++)
        {
            if (!(isalpha(argv[1][i])))
            {
                printf("Usage : ./vigenere keyword\n");
                break;
            }
            // The provided keyword contains only letters
            if (i == length - 1)
            {
                printf("Success\n");


                // Convert each character in the keyword to an integer and store in an array
                int keyword[length];
                for (int k = 0; k < length; k++)
                {

                    // Lowercase character
                    if (islower(argv[1][k]))
                    {
                        keyword[k] = (int) argv[1][k] - (int) 'a';
                    }
                    // Uppercase character
                    else
                    {
                        keyword[k] = (int) argv[1][k] - (int) 'A';
                    }
                }

                // Prompt user for a plaintext string
                string plaintext = get_string("plaintext: ");

                // Convert the plaintext to cyphertext
                // Rotate each ASCII value by 'keyword[count]' characters
                printf("ciphertext: ");
                int count = 0;
                for (int j = 0; j < strlen(plaintext); j++)
                {
                    count %= length;

                    // If character is upper case (ASCII 'A' to 'Z')
                    if (plaintext[j] >= (int) 'A' && plaintext[j] <= (int) 'Z')
                    {
                        if (plaintext[j] + keyword[count] > (int) 'Z')
                        {
                            plaintext[j] = (int) 'A' + ((keyword[count]  - 1 - ((int) 'Z' - plaintext[j])) % LETTERS_IN_ALPHABET);
                        }
                        else
                        {
                            plaintext[j] += keyword[count];
                        }
                    }

                    //If character is lower case (ASCII 'a' to 'z')
                    if (plaintext[j] >= (int) 'a' && plaintext[j] <= (int) 'z')
                    {
                        if (plaintext[j] + keyword[count] > (int) 'z')
                        {
                            plaintext[j] = (int) 'a' + ((keyword[count] - 1 - ((int) 'z' - plaintext[j])) % LETTERS_IN_ALPHABET);
                        }
                        else
                        {
                            plaintext[j] += keyword[count];
                        }
                    }
                    printf("%c", plaintext[j]);

                    if (isalpha(plaintext[j]))
                    {
                        count++;
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
    else
    {
        // Either no argument, or more than one argument was received
        printf("Usage : ./vigenere keyword\n");
    }
    return 1;
}
