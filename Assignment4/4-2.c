/*
 * Jacob Rammer
 * Assignment 4-2
 */

#include <stdio.h>

long sum(long n)
{
    if (n < 1)
        return 0;

    long i = 1;
    long result = 0;
    loop:
        if(i <= n)  // just move the while condition for the loop condition
        {
            result += i;
            i++;
            goto loop;
        }

    return result;
}


int main()
{
    printf("Test %ld\n", sum(7));
    return 0;
}