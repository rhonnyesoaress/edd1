#include <stdio.h>
#include <stdlib.h>

int main(){

    int a;

    printf("Sizeof(a) = %ld bytes\n", sizeof(a));
    printf("Sizeof(int) = %ld bytes\n", sizeof(int));
    printf("Sizeof(short) = %ld bytes\n", sizeof(short));
    printf("Sizeof(long) = %ld bytes\n", sizeof(long));
    printf("Sizeof(unsigned long) = %ld bytes\n", sizeof(unsigned long));
    printf("Sizeof(float) = %ld bytes\n", sizeof(float));
    printf("Sizeof(double) = %ld bytes\n", sizeof(double));

    printf("Sizeof(void *) = %ld bytes\n", sizeof(void *));
    printf("Sizeof(int *) = %ld bytes\n", sizeof(int *));
    printf("Sizeof(int **) = %ld bytes\n", sizeof(int **));
    printf("Sizeof(int ***) = %ld bytes\n", sizeof(int ***));
    printf("Sizeof(float *) = %ld bytes\n", sizeof(float *));


    return 0;

}