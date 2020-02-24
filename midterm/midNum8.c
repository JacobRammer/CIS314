#include <stdio.h>

int sum(int *a, int length)
{
    int result = 0;
    for(int i = 0; i < length; i++)
        result += a[i];
    return result;
}

int gotoSum(int* a, int length)
{
    int result = 0;
    int i = 0;
    LABEL:
        if(i > length)
        {
            result += a[i];
            i++;
            goto LABEL;
        }
    return result;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    printf("Sum is %d\n", sum(a, 5));
    printf("mySum is %d\n", sum(a, 5));
    return 0;
}

