/*
 * Jacob Rammer
 * Assignment 3-2
 */

#include <stdio.h>

long f(long long a, long long b, long long c)  // using long long because of gcc warnings
{
    c = c + b;  // addq %rsi, %rd (addition)
    a = a * c;  // imulq % rdx, %rdi (multiplication)
    c = c << 63;  // salq $63, %rdx
    c = c >> 63; // sarq $63, %rdx
    return a ^ c;  // xorq %rdx, %rax
}


int main()
{
    printf("%ld\n", f(1, 2, 4));
    printf("%ld\n", f(3, 5, 7));
    printf("%ld\n", f(10, 20, 30));
}