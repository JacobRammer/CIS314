#include <stdio.h>

/*
 * Jacob Rammer
 * Assignment 1-1
 */

unsigned int combine(unsigned int x, unsigned int y)
{
    x = (x & 0xFF000000); // creating a mask to isolate the 8 most significant bits
    y = (y & 0x00FFFFFF); // mask everything except the 8 most significant bits
    /*
     * With everything properly masked, or them to combine the two words
     * which will then be returned
     */
    return (x | y);

}


int main()
{
    printf("%#010x\n", combine(0x12345678, 0xABCDEF00));
    printf("%#010x\n", combine(0xABCDEF00, 0x12345678));

    return 0;
}
