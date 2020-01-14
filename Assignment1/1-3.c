#include <stdio.h>
/*
 * Jacob Rammer
 * 1-3
 */


int evenBit(unsigned int n)
{
    /*
     * accomplish this by masking the even bits only. Then compare them to not
     * 0 (0x00000001) and then not it which will leave the final word as a 0 or 1
     * which is then returned
     */

    return !!(n & 0x55555555);
}


int main()
{
    /* From lab
     * mask the even bits and use !! 5: 0101
     */


    printf("%d", evenBit(0xFFFFFFFF));
    return 0;
}