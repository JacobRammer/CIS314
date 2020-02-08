#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    long long * test = malloc(sizeof(long) * 100000000);
    label:
        printf("hello, world\n");
        if(a  == 5)
        {
            a++;
            goto label;
        }
    return 0;
}