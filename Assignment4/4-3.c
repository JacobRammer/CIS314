/*
 * Jacob Rammer
 * Assignment 4-3
 */

#include <stdio.h>

long fact(long x)  // x is a callee-saved variable, which will be stored (moved) to %rbx
{
    if(x <= 1)
        return 1;
    long px = x;
    long fx = fact(x - 1);
    /*      ^^
     * Since this is a recursive call, a temporary register will be used, which is %rbx
     */
    return px * fx;
}

/*
 * fact:
.LFB11:
	.cfi_startproc
	cmpq	$1, %rdi
	jle	.L3
	pushq	%rbx  store x since it's callee saved and is a recursive call
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	leaq	-1(%rdi), %rdi
	call	fact
	imulq	%rbx, %rax
	popq	%rbx  since factorials are multiplication, it pops the last result x off the stack and mults it with the return val
	.cfi_def_cfa_offset 8
	ret
 */

int main()
{
    printf("Fact 7 %lu\n", fact(7));
    printf("Fact 8 %lu\n", fact(8));
    return 0;
}