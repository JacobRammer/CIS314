/*
 * Jacob Rammer
 * Assignment 6-2
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 1000
void inner(float *u, float *v, int length, float *dest)
{
    int i = 0;
    float sum = 0.0f;
    for(i = 0; i < length; i++)
        sum += u[i] * v[i];

    *dest = sum;
}

void inner2(float *u, float *v, int length, float *dest)
{
    // the 4 parallel accumulators
    int i = 0;
    float sum = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;
    float sum4 = 0.0f;
    for(i = 0; i < length; i+= 4) // +=4 because of the new unrolling
    {
        sum += u[i] * v[i];
        sum2 += u[i +1] * v[i + 1];
        sum3 += u[i + 2] * v[i + 2];
        sum4 += u[i + 3] * v[i + 3];
    }
    // for the leftover items like discussed in class:
    for(; i < length; i++)
        sum += u[i] * v[i];

    *dest = sum + sum2 + sum3 + sum4;
}


float* createArray(int size)
{
    float* a = (float*)(malloc(sizeof(float) * SIZE));
    for(int i = 0; i < size; i++)
        a[i] = rand();
    return a;
}
void printArray(float* a, int size)
{
    int numZero = 0;
    for(int i = 0; i < size; i++)
    {
        printf("a[%d] is %f, ", i, a[i]);
        if(a[i] == 0)
            numZero++;
    }
    printf("\nNumber of zeros is: %d\n", numZero);
}



int main()
{
    clock_t start;
    clock_t end;
    double totalTime;
    float* a = createArray(SIZE);
    float* b = createArray(SIZE);
    float dest = 0;
    float dest2 = 0;
    start = clock();
    inner(a, b, SIZE, &dest);
    end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to execute inner is: %f\n", totalTime);
    start = clock();
    inner2(a, b, SIZE, &dest2);
    end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to execute inner2 is: %f\n", totalTime);
    /*
     * As expected, the function with loop unrolling is more efficient
     */



//    printf("destination is for inner: %f\n", dest);

//    printf("destination is for inner2: %f\n", dest2);
//    printArray(a, SIZE);
//    printArray(b, SIZE);
//    float* destination = 0;
//    inner(u, v, SIZE, &destination);
//    printf("Destination from u inner %f\n", *destination);
    return 0;
}