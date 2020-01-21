#include <stdio.h>

/*
 * Jacob Rammer
 * Assignment 2-3
 */

int ge(float x, float y) {
     unsigned int ux = *((unsigned int*) &x); // convert x raw bits
     unsigned int uy = *((unsigned int*) &y); // convert y raw bits
     unsigned int sx = ux >> 31; // extract sign bit of ux
     unsigned int sy = uy >> 31; // extract sign bit of uy
     ux <<= 1; // drop sign bit of ux
     uy <<= 1; // drop sign bit of uy

     return ((sx == 1 && sy == 1) && ux <= uy)  // if it's negative
            || ((sx == 0 && sy == 0) && ux >= uy)  // if the sign is positive
            || (ux == 0 && uy == 0)  // if both are 0
            || ((sx == 0 && sy ==1) &&  uy >= ux)  // if x is + and y is -
            ;
}


int main()
{
    printf("bool: %d\n", ge(0.0f, 0.0f));
    printf("bool: %d\n", ge(-0.0f, 0.0f));
    printf("bool: %d\n", ge(-1.0f, -1.0f));
    printf("bool: %d\n", ge(1.0f, 1.0f));
    printf("bool: %d\n", ge(-1.0f, 0.0f));
    printf("bool: %d\n", ge(0.0f, 1.0f));
    printf("bool: %d\n", ge(1.0f, 0.0f));
    printf("bool: %d\n", ge(0.0f, -1.0f));
    printf("bool: %d\n", ge(-1.0f, -2.0f));
//    printf("bool: %d\n", ge(-1.0f, 2.0f));

//    ge(0.0f, 0.0f): 1
//ge(-0.0f, 0.0f): 1
//ge(-1.0f, -1.0f): 1
//ge(1.0f, 1.0f): 1
//ge(-1.0f, 0.0f): 0
//ge(0.0f, 1.0f): 0
//ge(1.0f, 0.0f): 1
//ge(0.0f, -1.0f): 1
//ge(-1.0f, -2.0f): 1

    return 0;

}