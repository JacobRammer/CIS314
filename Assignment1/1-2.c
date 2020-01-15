#include <stdio.h>
/*
 * Jacob Rammer
 * assignment 1-2
 */

unsigned int replace(unsigned int x, int i, unsigned char b)
{
    i = (i << 3); // shift by the specified offset
    unsigned int ffMask = (0xFF << i); // create the mask
    unsigned int newVal = (b << i); // mast the bits that we want to replace to the correct place
    return (x & ~ffMask) | newVal;
    /*
     * X is the original word, not it with the ffmask which is now flipped and then or it
     * to combine the word
     */

}


int main()
{
    /*
     * from lab
     * 0x12345678 (want to keep 3 - 8)
     * 0xff << (3 << 3) = 3 * 8 = 2 ((or 6 * 4)?)
     * == FF000000
     * now ~ff000000
     */

    printf("%#010x\n", replace(0x12345678, 3, 0xAB));
    printf("%#010x\n", replace(0x12345678, 0, 0xAB));
    return 0;
}