// Calculates whether a given credit card number represents a valid
// MASTERCARD, VISA, or AMEX card, using Luhn's algorithm.
// Samantha Tripp
// 30/12/2018

#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    
    long long creditCardNumber;
    
    // Request credit card number from user
    do 
    {
        creditCardNumber = get_long_long("Number: ");
    } 
    while (creditCardNumber <= 0 || creditCardNumber == LLONG_MAX); 
    
    // Determine the length of the credit card number
    int numLength;
    long long x = creditCardNumber;
    
    while (x != 0)
    {
        x = x / 10;
        numLength ++;
    }
    
    // Create an integer array composed of each digit of the credit card number
    long long cardNumbers[numLength];
    long long modOperator = 10;
    
    for (int i = 0; i < numLength; i++)
    {
        cardNumbers[i] = creditCardNumber % modOperator;
        creditCardNumber -= cardNumbers[i];
        cardNumbers[i] /= modOperator / 10;
        modOperator *= 10;
    }
    
    // Determine if the number represents AMEX, VISA or MASTERCARD
    char c;
    if (cardNumbers[numLength - 1] == 5 && (numLength == 16))
    {
        if (cardNumbers[numLength - 2] == 1 
            || cardNumbers[numLength - 2] == 2 
            || cardNumbers[numLength - 2] == 3 
            || cardNumbers[numLength - 2] == 4 
            || cardNumbers[numLength - 2] == 5) 
        {
            c = 'M';
        } 
    } 
    else if (cardNumbers[numLength - 1] == 3) 
    {
        if ((cardNumbers[numLength - 2] == 4 
             || cardNumbers[numLength - 2] == 7)
            && numLength == 15)
        {
            c = 'A';
        } 
    } 
    else if (cardNumbers[numLength - 1] == 4 
             && (numLength == 13 || numLength == 16)) 
    {
        c = 'V';
    } 
    
    // CALCULATE CHECKSUM
    
    // Starting from second last digit, multiply every second digit by 2
    for (int i = 1; i < numLength; i += 2)
    {
        cardNumbers[i] *= 2;
    }
    
    // Add all individual digits together
    int checksum = cardNumbers[0];
    for (int i = 1; i < numLength; i++)
    {
        if (cardNumbers[i] > 9)
        {
            checksum += cardNumbers[i] % 10;
            cardNumbers[i] -= cardNumbers[i] % 10;
            cardNumbers[i] /= 10;
            checksum += cardNumbers[i];
        } 
        else 
        {
            checksum += cardNumbers[i];
        }
    }
    
    if (checksum % 10 == 0)
    {
        // Valid credit card number
        if (c == 'M')
        {
            printf("MASTERCARD\n");
        } 
        else if (c == 'A')
        {
            printf("AMEX\n");
        }
        else if (c == 'V')
        {
            printf("VISA\n");
        } 
        else 
        {
            // Not MASTERCARD, VISA or AMEX
            printf("INVALID\n");
        }
    }
    else
    {
        // Invalid credit card number
        printf("INVALID\n");
    }
    
}
   
