/* Cracks 5 character, alphabetic passwords hashed with C's DES-based crypt function
 * BRUTE FORCE method
 *
 * Samantha Tripp
 * 08/18/2019
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    // Ensure that command line argument "./crack hashed_password" was received
    if (argc == 2)
    {
        //Declare constant variables
        const int SALT = 2; // Hash manipulation key
        const int MAX_LENGTH = 5; // Max length of potential passwords
        const int ALPHABET = 26; // Number of letters in the alphabet
        const int UPPER_LOWER = ALPHABET * 2; // Number of upper and lower case letters

        // Check for invalid pointer
        if (!argv[1])
        {
            return 1;
        }

        // Store valid pointer in a variable
        char *hashed_password = argv[1];

        // Salt is recorded as the first 2 characters of the hashed password
        char *salt = malloc((SALT + 1) * sizeof(char));
        salt[0] = hashed_password[0];
        salt[1] = hashed_password[1];
        salt[2] = '\0'; //NUL terminator

        // Initialize string of test characters (alphabetic)
        char *test_chars = malloc((UPPER_LOWER + 1) * sizeof(char));
        int counter = 0;
        for (int i = (int) 'a'; i <= (int) 'z'; i++)
        {
            test_chars[counter] = (char) i;
            test_chars[counter + ALPHABET] = (char) i - ((int) 'a' - (int) 'A');
            counter++;
        }
        test_chars[UPPER_LOWER] = '\0'; //NUL terminator

        // Allocate memory for test passwords up to a length of 5 characters
        char *password = malloc((MAX_LENGTH + 1) * sizeof(char));

        counter = 1;
        password[counter] = '\0'; // Set NUL terminator

        // 5 character password
        for (int p = 0; p < UPPER_LOWER; p++)
        {
            // 4 character password
            for (int q = 0; q < UPPER_LOWER; q++)
            {
                // 3 character password
                for (int r = 0; r < UPPER_LOWER; r++)
                {
                    // 2 character password
                    for (int s = 0; s < UPPER_LOWER; s++)
                    {
                        // 1 character password
                        for (int t = 0; t < UPPER_LOWER; t++)
                        {
                            password[0] = test_chars[t];

                            // Encrypt test passoword and compare with hashed password
                            if (strcmp(crypt(password, salt), hashed_password) == 0)
                            {
                                // Success
                                printf("%s\n", password);

                                //Free memory
                                free(salt);
                                free(test_chars);
                                free(password);

                                return 0;
                            }

                            if (s == 0 && t == UPPER_LOWER - 1)
                            {
                                // Shift NUL terminator
                                counter ++;
                                password[counter] = '\0';
                            }
                        }
                        password[1] = test_chars[s];

                        if (r == 0 && s == UPPER_LOWER - 1)
                        {
                            // Shift NUL terminator
                            counter ++;
                            password[counter] = '\0';
                        }
                    }
                    password[2] = test_chars[r];

                    if (q == 0 && r == UPPER_LOWER - 1)
                    {
                        // Shift NUL terminator
                        counter ++;
                        password[counter] = '\0';
                    }
                }
                password[3] = test_chars[q];

                if (p == 0 && q == UPPER_LOWER - 1)
                {
                    // Shift NUL terminator
                    counter ++;
                    password[counter] = '\0';
                }
            }
            password[4] = test_chars[p];
        }
    }
    else
    {
        // Either no argument, or more than one argument was received
        printf("Usage : ./crack hashed_password\n");
    }
    return 1;
}