#include <stdio.h>
#include <stdlib.h>

int main(){

    float z = 2.5;
    float *fp;

    fp = &z;

    printf("&z = %.2f\n", *&z);
    printf("*fp = %.2f\n", *fp);
    printf("**&fp = %.2f\n", **&fp);

    return 0;
}