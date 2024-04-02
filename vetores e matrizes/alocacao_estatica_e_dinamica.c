#include <stdio.h>
#include <stdlib.h> // Contem o NULL, calloc(), malloc() e free()

int main(){
    //alocação de vetor estatico (memoria Stack)

    int v_s[5] = {0, 10, 20, 30, 40};

    puts("--- VETOR ESTÁTICO ---\n");

    for(int i = 0; i < 5; i++){
        printf("&v_s[%d] = %p, v_s[%d] = %d\n", i, &v_s[i], i, v_s[i]);
    }
    
    puts("");

    //alocação de vetor dinamico usando malloc (memoria Heap)

    int *vh_mall = (int *)malloc(5 * sizeof(int)); // Todo os elementos possuem lixo de memória.

    puts("--- VETOR DINAMICO MALLOC ---\n");

    printf("&vh_mall = %p, vh_mall = %p\n", &vh_mall, vh_mall);

    for(int i = 0; i < 5; i++){
        printf("&vh_mall[%d] = %p, vh_mall[%d] = %d\n", i, &vh_mall[i], i, vh_mall[i]);
    }
    
    puts("\n");



    //alocação de vetor dinamico usando calloc (memoria Heap)

    int *vh_call = (int *)calloc(5 , sizeof(int)); // Garante que todos os elementos do bloco alocado recebam o valor 0.

    puts("--- VETOR DINAMICO CALLOC ---\n");

    printf("&vh_call = %p, vh_call = %p\n", &vh_call, vh_call);

    for(int i = 0; i < 5; i++){
        printf("&vh_call[%d] = %p, vh_call[%d] = %d\n", i, &vh_call[i], i, vh_call[i]);
    }
    
    puts("\n");

    // NAO ESTAMOS DESALOCANDO OS VETORES DINAMICOS
    
    return 0;
}