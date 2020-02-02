/*
 * Jacob Rammer
 * Assignment 3-1
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int length;
    int *dataPtr;

}IntArray;


IntArray* mallocIntArray(int length)
{
    /*
     * Function to initialize and return an IntArray
     */

    IntArray *ia = malloc(sizeof(IntArray));  // allocate memory for the IntArray object
    ia->dataPtr = malloc(sizeof(int) * length);  // allocate memory for the pointer array
    ia->length = length;
    return ia;
}

void freeIntArray(IntArray *arrayPtr)  // just frees the memory for the struct and dataPtrs
{
    /*
     * Free memory allocated by creating an int array object
     */

    free(arrayPtr->dataPtr);
    free(arrayPtr);
}

void readIntArray(IntArray *array)
{
    /*
     * Add items to the intArray dataPtr array from user input.
     * Only accepts number greater than 0
     */

    for(int i = 0; i < array->length; i++)
    {
        char userNum[sizeof(int) * array->length];  // char is 1 byte, ran with valgrind, no errors.
        // Turns out giving that 1 byte is dangerous, only took me a few to figure out memory issues lol
        char *num;
        printf("Enter int:");
        fgets(userNum, 10, stdin);
        int test = strtol(userNum, &num, 10);
        if(strtol(userNum, &num, 10) == 0)  // error checking
        {
            printf("Invalid input\n");
            i--;
        } else  // only assign data if input is valid
        {
            array->dataPtr[i] = test;
        }

    }

}

void swap(int *xp, int *yp)
{
    /*
     * Swap items based on index location in the dataPtr array
     */

    int tempX = *yp;  // create a temp y copy since i'm reassigning yp right away
    *yp = *xp;
    *xp = tempX;
}

void sortIntArray(IntArray *array)
{
    /*
     * Sort the dataPtr array from least to greatest.
     * Based on bubble sort from: bubble sort inspired by https://www.geeksforgeeks.org/bubble-sort/
     */

    for(int i = 0; i < (array->length) - 1; i++)
    {
        for(int j = 0; j < (array->length) - i - 1; j++)
        {
            if(array->dataPtr[j] > array->dataPtr[j + 1])
                swap(&array->dataPtr[j], &array->dataPtr[j + 1]);
        }
    }
}

void printIntArray(IntArray *array)
{
    /*
     * Print everything in the dataPtr array
     */

    for(int i = 0; i < array->length; i++)
    {
        printf("i = %d, %d\n", i, array->dataPtr[i]);
    }
}

int main()
{
    char userNum[1];  // char is 1 byte, ran with valgrind, no errors
    char *num;
    printf("Enter length:");
    fgets(userNum, 10, stdin);
    int length = strtol(userNum, &num, 10);
    if(length <= 0 || strtol(userNum, &num, 10) == 0)
    {
        /*
         * From strtol documentation: strtol will return 0 if there
         * is an error parsing non digit input
         */
        printf("Invalid input\n");
        main();
    }
    IntArray *newArray = mallocIntArray(length);
    readIntArray(newArray);
//    sortIntArray(newArray);
//    printIntArray(newArray);
//    freeIntArray(newArray);  // valgrind is happy
    return 0;
}