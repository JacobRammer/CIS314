/*
 * Jacob Rammer
 * Assignment 6-3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

float f(float* a, int n)
{
    float prod = 1.0f;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0.0f)
            prod *= a[i];
    }

    return prod;
}


float g(float* a, int n)
{
    float prod = 1.0f;
    for(int i = 0; i < n; i++)
        prod *= a[i];

    return prod;
}


float* createArray(int size)
{
    float* a = (float*)malloc(size * sizeof(float));
    for(int i = 0; i < size; i++)
    {
        // 50% chance that a[i] is 0.0f, random value on the range
        // [0.76, 1.26] otherwise.

        float r = rand() / (float)RAND_MAX;
        a[i] = r < 0.5f ? 0.0f : r + 0.26f;
    }

    return a;
}

void printArray(float* a, long size)
{
    int numZero = 0;
    for(long i = 0; i < size; i++)
    {
//        printf("a[%d] is %f, ", i, a[i]);
        if(a[i] == 0)
            numZero+= 1;
    }
    printf("\nNumber of zeros is: %d\n", numZero);
}


int main()
{
    clock_t start;
    clock_t end;
    double totalTime = 0;

    start = clock();
    float* a = createArray(SIZE);
    end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to create array: %f seconds. \n", totalTime);
    // avg: .000700 - .000222

    // create array with zeros replaced with ones
    float* b = malloc(sizeof(float) * SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        if(a[i] != 0)
            b[i] = a[i];
        else
            b[i] = 1.0f;

    }

    // f(a)
    start = clock();
    f(a, SIZE);
    end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to call f(a): %f seconds. \n", totalTime); //about .000070 avg without -Og

    // g(b)
    start = clock();
    g(b, SIZE);
    end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to call g(b): %f seconds. \n", totalTime); // about .000026 avg w/o -Og
    /*
     * Short write up of the two function calls above
     *
     * I am using Clion for my IDE. When running the two function calls
     * above, f(a) takes quite a bit longer than g(b). I have not messed with the
     * default compile settings, so I assume it is not using any optimisation flags.
     * So this means that f(a) is evaluating the if every time through the loop and
     * applying the multiplication operation.
     *
     * When using the -Og flag, the run times are essentially the same.
     * Sometimes f(a) is slower and sometimes g(b) is slower, which is
     * to be expected do to margin of error. This is because the -Og flag
     * provides little optimization, but I'm sure gcc is smart enough to
     * know anything multiplied by 1.0f is itself, so the executable is
     * optimised not to skip the loop multiplying a[i] by 1. So leading
     * the execution times to essentially be the same / function g is faster
     *
     * When using the -Og flag and diving into the assembly code (in MacOS):
     * without -Og:
     * jne	LBB0_3
	 *   jp	LBB0_3
     *  jmp	LBB0_4
     *  are are instructions in f, which are missing in g
     *
     *  if I use the -Og flag I get:
     *  jne	LBB0_4
     *  as the only JP instruction, which is the same instruction for g with and without
     *  optimisation flags. So the thing slowing down f is the if statements.
     *
     *  reading from piazza, it seems that I am having the same issue as someone
     *  else with the function calls are running too quick to be timed and can't fix it.
     *  Even with this said I know enough of what's going on to stay with my conclusion.
     */

    // Create array c

    //count # of zeros in a
    int zeros = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(a[i] == 0)
            zeros++;
    }
//    printf("Number of zeros: %d\n", zeros);
    float* c = malloc(sizeof(float) * zeros);
    int j = 0; // what I'll use for indexing c
    for(int i = 0; i < SIZE; i++)
    {
        if(a[i] != 0.0f)
        {
            c[j] = a[i];
            j++;
        }
    }
//    printArray(a, SIZE);
//    printArray(c, zeros);

    // time g(c)
    start = clock();
    g(c, zeros);
    end = clock();
    printf("Time to call g(c): %f seconds. \n", totalTime); // g(b) and g(c) have same time

    /*
     * I'm going to keep this write up shorter because I believe I covered
     * everything important in the previous writeup.
     * In my testing, even with size changed to very high numbers the run time
     * of f(a), g(b) and g(c) were the same with or without optimisations
     */




//    printArray(a, SIZE);
//    printArray(a, SIZE);
    printArray(c, SIZE);
    free(b);
    free(a);
    free(c);
    return 0;
}