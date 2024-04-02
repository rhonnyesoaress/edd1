#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livro{
    char titulo[100];
    int num_pag;
    float preco;
}Livro;

Livro *create_livro(const char *titulo, int num_pag, float preco){

    Livro *livro = (Livro*)calloc(1, sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->num_pag = num_pag;
    livro->preco = preco;

    return livro;
}

void print_livro(const Livro *livro){
    printf("Titulo = %s\n", livro->titulo);
    printf("Paginas = %d\n", livro->num_pag);
    printf("Preco = %.2f\n", livro->preco);
    puts("");
}

void destroy_livro(Livro **livro_ref){
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}

int main(){

    Livro **vet = (Livro**)calloc(3, sizeof(Livro*));

    vet[0] = create_livro("Harry Potter 1", 200, 10);
    vet[1] = create_livro("A culpa e das Estrelas", 150, 15);
    vet[2] = create_livro("Peter Pan", 60, 5);

    for(int i = 0; i < 3; i++){
        print_livro(vet[i]);
    }

    for(int i = 0; i < 3; i++){
        destroy_livro(&vet[i]);
    }
    free(vet);
    vet = NULL;

    return 0;
}