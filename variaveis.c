#include <stdio.h>

int main(){

    int a = 10;
    int b, c;

    printf("Valor a: %d e Endereço de a: %p\n", a, &a);
    printf("Valor b: %d e Endereço de b: %p\n", b, &b);
    printf("Valor c: %d e Endereço de c: %p\n", c, &c);

    b = 20;
    c = a + b;

    printf("Valor a: %d e Endereço de a: %p\n", a, &a);
    printf("Valor b: %d e Endereço de b: %p\n", b, &b);
    printf("Valor c: %d e Endereço de c: %p\n", c, &c);
    return 0;
}