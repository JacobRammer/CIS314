#include <stdio.h>

long sum(long start)
{
    long result = 0;
    label:
    if(start != 0)
    {
        result += start;
        start--;
        goto label;
    }
    printf("%d\n", start);

    return result;
}


int main()
{

    printf("Calling sum %ld", sum(5));
    return 0;
}