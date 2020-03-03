#include <stdio.h>

int f(int a, int b, int c, int d, int n)
{
    int ab = a * b;
    int cd = c * d;
    int i = 1;
    int icd = i * c * d;
    int result = (n * n) * a * b + n * (n * (n - 1))
            / 2 * c * d + (n * (n - 1)) * n / 2;

     /*
      * Piazza led me down the road to figure out the formula post @ 119
      * so breaking the loop down, we have n*n, a* b, n - 1 for length
      *
      * 2 n
      *
      * loop 1:
      * (n * n) * a * b + n * (n * (n - 1))/ 2
      * loop2:
      * loop1 *= * c * d + (n * (n - 1)) * n / 2
      */

//     this actually doesn't work
//     for (i = 1; i < n; ++i)
//     {
//        for (int j = 0; j < n + 1; ++j)
//        {
//        result += ab + icd + cd + j;
//
//        }
//     }


     return result;
}

int main()
{
    printf("Should be 700: %d\n", f(1, 2, 3, 4, 5));
    printf("Should be 2106: %d\n", f(2, 3, 4, 5, 6));
    printf("Should be 146: %d\n", f(6, 5, 4, 3, 2));
    printf("Should be 20: %d\n", f(5, 4, 3, 2, 1));
}
