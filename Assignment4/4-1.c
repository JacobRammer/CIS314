/*
 * Jacob Rammer
 * Assignment 4-1
 */

#include <stdio.h>

long loop(long x, long y)
{
    /*
     * x = %rdi
     * y = %rsi
     */
    long result = -1;  // movq $-1, %rdx
    for(long mask = 2; mask > 1; mask <<= y)
    /*
     * since y is a counter and 8 bits, it can be stored in %cl
     * mask > 1: cmpq $1, %rax
     */
    {
        result ^= (x & mask);
        /*
         * mask - %rax is moved to the %r8 register.
         * which is then &'d with %rdi which is x which
         * is then ^'d with result.\a
         * this corresponds with:
         * andq %rdi, %r8
         * xorq %r8, %rdx
         *
         */
    }
    return result;
}


int main()
{
    printf("Loop 1: %ld\n", loop(1, 5));
    printf("loop 2: %ld\n", loop(2, 4));
    printf("loop 3: %ld\n", loop(3, 3));
    printf("loop 4: %ld\n", loop(4, 2));
    printf("loop 5: %ld\n", loop(5, 1));
    return 0;
}