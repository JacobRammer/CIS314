/*
 * Jacob Rammer
 * Assignment 4-4
 */

#include <stdio.h>

#define N 4
typedef long array_t[N][N];

void transpose(array_t a) {
     for (long i = 0; i < N; ++i) {
         for (long j = 0; j < i; ++j) {
             long t1 = a[i][j];
             long t2 = a[j][i];
             a[i][j] = t2;
             a[j][i] = t1;
         }
     }
}

void optimizedTranspose(array_t a)  // this mainly follows the slides from class
{
    /*
    * A[i][j] is element of type T, which requires K bytes
    * Address  A + i * (C * K) +  j * K 
    * Actually after a few slides it gives the outline for the algorith below
    */


    for(int i = 0; i < N; i++)
    {
        long *col = &a[0][i];  // hint from slides for index for both row and column 
        long *row = &a[i][0];
        for(int j = 0; j < i; j++)
        {            
            long temp1 = *row;
            long temp2 = *col;
            *row = temp2;  // will swap column with row
            *col = temp1;  // swap row with column
            col += N;
            row++;
            /*
            * Add 1 to row (which will be 1 * 8) to the location of row
            *  Increment column by 4 (4 * 8) to get to the next list
            * {{1, 2, 3, 4}
            * {5, 6, 7, 8}
            * {9, 10, 11, 12}
            * {13, 14, 15, 16}}
            */
        }
    }
}

void testPrint(array_t a)
{
    for(int i = 0; i < N; i++)
    {
        printf("{");
        for(int j = 0; j < N; j++)
            printf("%ld ", a[i][j]);
        printf("}, ");
    }
    printf("\n");
}
int main()
{
    array_t test = { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16} };

    optimizedTranspose(test);
    testPrint(test);
    return 0;
}

/*
L3:
movq (%rax), %rcx, put array lookup in t1
movq (%rdx), %rsi put array lookup in t2
movq %rsi, (%rax) next 2 lines are the swap. t1 into a[j][i]
movq %rcx, (%rdx) t2 into a[i][j]
addq $8, %rax  add 8 to t1 for long data type
addq $32, %rdx add 32 to t2 (since it's 4 * 8 bytes for long)
cmpq %r9, %rax inner loop i, j compare
jne .L3  if the loop condition is not met
*/