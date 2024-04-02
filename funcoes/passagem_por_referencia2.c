#include <stdio.h>
#include <stdlib.h>

int soma_e_sub(int x, int y, int *sub){

    int soma = x + y;
    *sub = x - y;

    puts("-----DURANTE A FUNÇÃO-----");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&sub = %p, sub = %p\n", &sub, sub);

    return soma;

}


int main(){

    int a = 10;
    int b = 20;
    int c, d;

    puts("-----ANTES DA FUNÇÃO-----");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&d = %p, d = %d\n", &d, d);

    c = soma_e_sub(a, b, &d);

    puts("-----DEPOIS DA FUNÇÃO-----");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&d = %p, d = %d\n", &d, d);

    return 0;
}