/*
 * Jacob Rammer
 * Assignment 7-2
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 2048

typedef struct
{
    long a;
    long r;
    long g;
    long b;
} ColorPoint;

ColorPoint** create2DArray(int n)
{
     // Array to hold a pointer to the beginning of each row
      ColorPoint **points =
              (ColorPoint **)malloc(n * sizeof(ColorPoint *));
       for (int i = 0; i < n; ++i)
       {
           // Array to hold each row
           points[i] =
                   (ColorPoint *) malloc(n * sizeof(ColorPoint));
           for (int j = 0; j < n; ++j)
           {
                // Init the ColorPoint struct
                 points[i][j].a = rand();
                 points[i][j].r = rand();
                 points[i][j].g = rand();
                 points[i][j].b = rand();
           }
       }
       return points;
}

void free2DArray(ColorPoint** points, int n)
{
    for (int i = 0; i < n; ++i)
    {
    free(points[i]);
    }
    free(points);
}

long g(ColorPoint **points, int n) {
     long sum = 0;
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             sum += points[i][j].a;
             sum += points[i][j].r;
             sum += points[i][j].g;
             sum += points[i][j].b;
        }
    }
    return sum;
}

long f(ColorPoint **points, int n) {
     long sum = 0;
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             sum += points[j][i].a;
             sum += points[j][i].r;
             sum += points[j][i].g;
             sum += points[j][i].b;
        }
    }
    return sum;
}

int main()
{
    clock_t start;
    clock_t end;
    double totalTime = 0;

    ColorPoint** points = create2DArray(SIZE);
    start = clock();
    long callF = f(points, SIZE);end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to call f(a): %f seconds. \n", totalTime);
    printf("Long f: %ld\n", callF);

    start = clock();
    long callG = g(points, SIZE);
    end = clock();
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime to call g(a): %f seconds. \n", totalTime);
    printf("Long g: %ld\n", callG);

    /*
     * As expected, g is faster. This is because we are iterating
     * the rows, and not the columns like in f. This makes a difference
     * because of the way memory is laid out (in a row), thus there
     * are less misses in g than in f.
     *
     * Time to call f(a): 0.035000 seconds.
        Long f: -23228672

        Time to call g(a): 0.016000 seconds.
        Long g: -23228672
     */

    free(points);
    return 0;
}