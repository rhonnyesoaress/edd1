#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y){

    int aux = *x;
    *x = *y;
    *y = aux;

    puts("-----DURANTE A FUNÇÃO-----");
    printf("&x = %p, x = %p\n", &x, x);
    printf("&y = %p, y = %p\n", &y, y);
    printf("&aux = %p, aux = %d\n", &aux, aux);
}


int main(){

    int a = 10;
    int b = 20;

    puts("-----ANTES DA FUNÇÃO-----");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);

    troca(&a, &b);

    puts("-----DEPOIS DA FUNÇÃO-----");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);


    return 0;

}