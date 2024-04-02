#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 10;
    int *p1 = NULL;
    int *p2;

    printf("&a %p e A: %d\n", &a, a);
    printf("&P1: %p e P1: %p\n", &p1, p1);
    printf("&P2: %p e P2: %p\n", &p2, p2);
    printf("------------------\n");
    p1 = &a;
    p2 = p1;
    *p2 = 4;

    printf("&a: %p e A: %d\n", &a, a);
    printf("&P1: %p e P1: %p e Conteudo de P1: %d\n", &p1, p1, *p1);
    printf("&P2: %p e P2: %p e Conteudo de P2: %d\n", &p2, p2, *p2);

    return 0;
}