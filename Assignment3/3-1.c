#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int length;
    int *dataPtr;

}IntArray;


IntArray* mallocIntArray(int length)
{
    IntArray *ia = malloc(sizeof(IntArray));  // allocate memory for the IntArray struct
    ia->dataPtr = malloc(sizeof(long) * length);  // allocate memory for the pointer array
    return ia;
}

void freeIntArray(IntArray *arrayPtr)  // just frees the memory for the struct and dataPtrs
{
    free(arrayPtr->dataPtr);
    free(arrayPtr);
}

void readIntArray(IntArray *array)
{
    for(int i = 0; i < 3; i++)
    {
        char userNum[1];
        char *num;
        printf("Enter length:");
        fgets(userNum, 10, stdin);
        int test = strtol(userNum, &num, 10);
        printf("%d\n", test);
    }
}

int main()
{
    readIntArray(5);
    return 0;
}