#include <stdio.h>
/*
 * Jacob Rammer
 * Assignment 2-1
 */

int mask(int x)
{
    /*
     * Since 1 is a power of 2, when everything is shifted, all bits will
     * become a 1. And since the word is 0 indexed, subtract 1 from x
     */
    return (1 << x) - 1;
}


int main()
{
    printf("0x%X\n", mask(1));
    printf("0x%X\n", mask(2));
    printf("0x%X\n", mask(3));
    printf("0x%X\n", mask(5));
    printf("0x%X\n", mask(8));
    printf("0x%X\n", mask(16));
    printf("0x%X\n", mask(31));


    return 0;
}