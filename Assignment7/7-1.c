/*
 * Jacob Rammer
 * Assignment 7-1
 */

#include <stdio.h>

unsigned int getOffset(unsigned int address)
{
    // 0x12345678: offset: 78

    return 0x000000FF & address;  // just return the last 8 bytes
}

unsigned int getSet(unsigned int address)
{
    // 0x12345678: set: 6


    return (address & 0x0000F00) >> 8;  // mask and dump the last 2 words
}

unsigned int getTag(unsigned int address)
{
    // 0x12345678: 12345

    unsigned int newAddr =  0xf0000000;

    return (address & 0xfffff000) >> 12;  // mask and dump the least 3 words
}

int main()
{
    // 0x12345678: offset: 78 - tag: 12345 - set: 6
    // 0x87654321: offset: 21 - tag: 87654 - set: 3

    printf("Tag: %x\n", getTag(0x12345678));
    printf("Set: %x\n", getSet(0x12345678));
    printf("Offset: %x\n", getOffset(0x12345678));

    printf("\nTag: %x\n", getTag(0x87654321));
    printf("Set: %x\n", getSet(0x87654321));
    printf("Offset: %x\n", getOffset(0x87654321));

    printf("\nTag: %x\n", getTag(0x54321987));
    printf("Set: %x\n", getSet(0x54321987));
    printf("Offset: %x\n", getOffset(0x54321987));

    return 0;
}