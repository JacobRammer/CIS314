/*
 * Jacob Rammer
 * Assignment 3-2
 */

#include <stdio.h>

int f(int a, int b, int c)
{
    c = c + b;
    return 0;
}


int main()
{
    printf("%d\n", f(1, 2, 4));
}