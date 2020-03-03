#include <stdio.h>

int f(int a, int b, int c, int d, int n)
{
    int ab = a * b;
    int cd = c * d;
    int i = 1;
    int icd = i * c * d; // set i to 1 so it doesn't * by 0 on first iteration
    int result = 0;
     for (i = 0; i < n; ++i)
     {
        for (int j = 0; j < n; ++j)
        {
        result += ab + icd + cd + j;
        }
     }
     return result;
}

int main()
{
    printf("Should be 700: %d\n", f(1, 2, 3, 4, 5));
    printf("Should be 2106: %d\n", f(2, 3, 4, 5, 6));
    printf("Should be 146: %d\n", f(6, 5, 4, 3, 2));
    printf("Should be 20: %d\n", f(5, 4, 3, 2, 1));
}
