/*
 * Jacob Rammer
 * Assignment 4-2
 */

#include <stdio.h>

//long sum(long n)  I misread the assignment, but this is everything with goto statements
//{
//    if (n < 1)
//        return 0;
//
//    long i = 1;
//    long result = 0;
//    loop:
//        if(i <= n)  // just move the while condition for the loop condition
//        {
//            result += i;
//            i++;
//            goto loop;
//        }
//
//    return result;
//}

long sum(long n)
{
    if(n < 1)
        return 0;
    long i = 1;
    long result = 0;
    // Ensure that argument *n* is in %rdi, *i* is in %rcx,
    // *result* is in %rax - do not modify.
    __asm__ ("movq %0, %%rdi # n in rdi;" :: "r" ( n ));
    __asm__ ("movq %0, %%rcx # i in rcx;" :: "r" ( i ));
    __asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));
    // Your x86-64 code goes below - comment each instruction...
    /*
     * TODO - Replace the two lines below with add, compare,
     * // jump instructions, labels, etc as necessary to implement
     * // the loop.
     */
    __asm__(
            ".LABEL:"
            "addl %rcx, %rax;" // add i to result which is return value
            "addl $1, %rcx;"  // increment i by 1
            "cmpl %rcx, %rdi;"  // compare them for the if statement
            "jle .LABEL"  // if i is not <= n, jump
    );
    // Ensure that *result* is in %rax for return - do not modify.
    __asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
    return result;
}


int main()
{
    printf("Test %ld\n", sum(1));
    return 0;
}