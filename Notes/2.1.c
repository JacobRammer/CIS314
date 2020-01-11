#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y=*x^*y; /*Step1*/
    *x=*x^*y; /*Step2*/
    *y=*x^*y; /*Step3*/

    printf("Y = %d, x = %d, y = %d", &[y, x, y);
}

int main()
{
    inplace_swap(10, 11);
    return 0;
}

