How to find length of a string without string.h and loop in C?
September 11, 2013
Find the length of a string without using any loops and string.h in C. Your program is supposed to behave in following way:
You may assume that the length of entered string is always less than 100.

The following is solution.

#include <stdio.h>
 
int main()
{
     char str[100];
     printf("Enter a string: ");
     printf( "\rLength is: %d",
              printf("Entered string is: %s\n", gets(str)) - 20
           );
 
     return 0;
}

The idea is to use return values of printf() and gets().
gets() returns the enereed string.
printf() returns the number of characters successfully written on output.

--------------------------------------------------------------------------------------------------------------------------------------------

