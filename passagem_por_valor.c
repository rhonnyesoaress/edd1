#include <stdio.h>
#include <stdlib.h>

int soma(int x, int y){

    int z = x + y;

    puts("-----DENTRO DA FUNÇÃO-----");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&z = %p, z = %d\n", &z, z);

    return z;
}

int main(){

    int a = 10;
    int b = 20;
    int c;
    
    puts("-----ANTES DA FUNÇÃO-----");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    c = soma(a, b);

    puts("-----DEPOIS DA FUNÇÃO-----");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    return 0;
}