/*
 * Jacob Rammer
 * Assignment 4-1
 */

#include <stdio.h>

long loop(long x, long y)
{
    /*
     * x = %rdi
     * y = %rsi
     */
    long result = -1;
    for(long mask = 2; mask > 1; mask <<= y)
    {
        result ^= (x & mask);
    }
    return result;
}


int main()
{
    printf("Loop %ld\n", loop(1, 5));
    printf("loop 2 %ld\n", loop(5, 1));
    return 0;
}