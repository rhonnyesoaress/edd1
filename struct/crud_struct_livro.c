#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livro{
    char titulo[100];
    unsigned int num_pag;
    float preco;
} Livro;

typedef struct _aluno{
    char nome[100];
    int idade;
    Livro *livro_fav;
} Aluno;

Livro *create_livro(const char *titulo, int num_pag, float preco){

    Livro *livro = (Livro *)calloc(1, sizeof(Livro));

    strcpy(livro -> titulo, titulo);
    livro -> num_pag = num_pag;
    livro -> preco = preco; 

    return livro;
}

void destroy_livro(Livro **livro_ref){
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}

Livro *copy_livro(const Livro *livro){
    return create_livro(livro->titulo, livro->num_pag, livro->preco);
}

void print_livro(const Livro *livro){
    printf("Título = %s\n", livro->titulo);
    printf("Páginas: %d\n", livro->num_pag);
    printf("Preço: %.2f\n\n", livro->preco);
}

Aluno *create_aluno(const char *nome, int idade, Livro *livro_fav){

    Aluno *aluno = (Aluno*)calloc(1, sizeof(Aluno));

    strcpy(aluno -> nome, nome);
    aluno -> idade = idade;
    aluno -> livro_fav = copy_livro(livro_fav);

    return aluno;
}

void destroy_aluno(Aluno **aluno_ref){
    Aluno *aluno = *aluno_ref;

    destroy_livro(&aluno->livro_fav);
    free(aluno);
    *aluno_ref = NULL;
}

void print_aluno(const Aluno *aluno){
    printf("Nome = %s\n", aluno->nome);
    printf("Idade = %d\n", aluno->idade);
    puts("LIVRO FAVORITO");
    puts("------");
    print_livro(aluno->livro_fav);
}

int main(){

    Livro *livro_harry = create_livro("Harry Potter Azkaban", 200, 35.50);
    print_livro(livro_harry);
    livro_harry -> preco = 10.50;
    print_livro(livro_harry);

    Aluno *ted = create_aluno("Ted", 20, livro_harry);
    print_aluno(ted);

    destroy_livro(&livro_harry);

    print_aluno(ted);

    destroy_aluno(&ted);

    return 0;
}