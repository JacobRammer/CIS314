#include <stdio.h>

/*
 * Jacob Rammer
 * Assignment 1-1
 */

unsigned int combine(unsigned int x, unsigned int y)
{
    x = (x >> 24);  // isolate the two most significant bits (6 * 4 = 24)
    x = (x << 24);  // shift them back so they're in the most significant order
    y = (y << 8);  // knock off the two most significant bits ( 2 * 4 = 8)
    y = (y >> 8);  // shift them back
    unsigned int final = (x | y);  // or them so that they are combined
    return final;
}


int main()
{
    /*
     printing hex to console: https://stackoverflow.com/questions/14733761/printf-formatting-for-hex
    */

    printf("%#010x\n", combine(0x12345678, 0xABCDEF00));  // cite needed;
    printf("%#010x\n", combine(0xABCDEF00, 0x12345678));

    return 0;
}