#include <stdio.h>

/*
 * Jacob Rammer
 * Assignment 2-2
 */

unsigned int extract(unsigned int x, int i)
{
    /* from lab 1
     * 0xff << (3 << 3) = 3 * 8 = 24
     */
    unsigned int leftOffset =  24 - (i << 3);  //from lab 1: i << 3 => i * 3
    int newWord = x << leftOffset; // shift the bits to position indicated above
    return (unsigned int) (newWord >> 24);
    /*              ^^^^^^
     * From Piazza: convert unsigned ints to signed, then return as unsigned
     * casting the newWord as an unsigned int then shifting the wanted bits to
     * the beginning of the word.
     */
}


int main()
{
    printf("%#010x\n", extract(0x8F000000, 3));
    return 0;
}