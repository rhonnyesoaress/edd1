#include <stdio.h>
#include <stdlib.h>

typedef struct _livro{
    char titulo[100];
    float preco;
    int n_pag;
}Livro;

int main(){

    Livro livro1;
    Livro *livro2 = (Livro*)calloc(1, sizeof(Livro));

    printf("Tamanho livro1 = %ld bytes\n", sizeof(livro1));
    printf("Tamanho livro2 = %ld bytes\n", sizeof(livro2));
    printf("Tamanho *livro2 = %ld bytes\n", sizeof(*livro2));
}