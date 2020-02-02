/*
 * Jacob Rammer
 * Assignment 3-2
 */

#include <stdio.h>

long f(long a, long b, long c)
{
    /*
     * c = rdx
     * b = rdi
     * a = rdi
     */
    c = c + b;  // addq %rsi, %rd (addition)
    a = a * c;  // imulq % rdx, %rdi (multiplication)
    c = c << 31;  // salq $63, %rdx
    c = c >> 31; // sarq $63, %rdx
    return a ^ c;  // xorq %rdx, %rax
}


int main()
{
    printf("%d\n", f(1, 2, 4));
    printf("%d\n", f(3, 5, 7));
}