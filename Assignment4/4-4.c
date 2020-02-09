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
int main()
{
    long test[7][7] = {{5, 4, 3, 2, 1}, {9, 0}};
    long *tt = *(test + 1);
    printf("test %ld\n", *tt);
    printf("test %ld\n", **(test + 8));
    return 0;
}