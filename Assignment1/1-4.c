#include <stdio.h>
/*
 * Jacob Rammer
 * 1-4
 */

void printBytes(unsigned char *start, int len)
{
     for (int i = 0; i < len; ++i)
     {
        printf(" %.2x", start[i]);
     }
     printf("\n");
}

void printInt(int x)
{
    printBytes((unsigned char *) &x, sizeof(int));
}
void printFloat(float x)
{
    printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x)
{
    printBytes((unsigned char *) &x, sizeof(float));
}

void printLong(long x)
{
    printBytes((unsigned char *) &x, sizeof(float));
}

void printDouble(double x)
{
    printBytes((unsigned char *) &x, sizeof(float));
}

int main()
{
    /*
     * So it looks like that the printBytes function is printing the hex in reversed order
     * where the least significant is on the left and the most is on the right.
     * If I plugged in some of these numbers into an online conversion tool,
     * the output is what I expected (most to least significant). Even though the book
     * claims this is normal it still throws me off.
     */
    printInt(54321); // 31 d4 00 00
    printFloat(654.789); //  7f b2 23 44
    printShort(432); //  b0 01 90 ea
    printLong(987654321); //  b1 68 de 3a
    printDouble(321.987); // 6f 12 83 c0

    return 0;
}