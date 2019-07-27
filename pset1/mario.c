// Prints out a Super Mario Bros pyramid of hashes of a user-specified 
// height between 1 and 22 levels.
// Samantha Tripp
// 07/2017

#include <stdio.h>
#include <cs50.h>


void say(string word, int x);

int main(void)
{
    int x;
    printf("Height: ");
    
    do
    {
        x = get_int();
        
        if (x < 0 || x >23)
        {
            printf("Height: ");
        }
    }
    while ( x < 0 || x > 23);
    
    for (int i=1; i<(x+1); i++)
    {
        say(" ", (x-i));
        say("#", (i));
        printf("  ");
        say("#", (i));
        printf("\n");
    }
}
void say(string word, int x)
{
   for (int i=0; i<x; i++)
   {
        printf("%s", word);
   }
}