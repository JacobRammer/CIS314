#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y)
{
    y = (y & 0x00ffffff);
    unsigned int leftMask = (x & 0xff000000);
//    printf("y is %#01X\n", y);
//    printf("x is %#01X\n", x);
    return leftMask | y;
}

unsigned int replace(unsigned int x, int i, unsigned char b)
{
    i = (i << 3);
    unsigned int mask = (0xFF << i);
    unsigned int newVal = (b << i);
    printf("i is %#01X\n", i);
    printf("x is %#01X\n", x);
    printf("mask is %#01X\n", mask);
    printf("NewVal is %#01X\n", newVal);
    return (x & ~mask) | newVal;
}


int main()
{
    printf("Combine is %#01X\n", combine(0x12345678, 0xABCDEF00));
    printf("Combine is %#01X\n", combine(0xABCDEF00, 0x12345678));
    printf("replace %#01X\n", replace(0x12345678, 3, 0xAB));
    return 0;
}