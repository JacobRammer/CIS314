/*
 * Jacob Rammer
 * Assignment 4-3
 */

#include <stdio.h>

long fact(long x)
{
    if(x <= 1)
        return 1;
    long px = x;
    long fx = fact(x - 1);
    return px * fx;
}

int main()
{
    printf("Fact 1 %lu\n", fact(7));
    return 0;
}