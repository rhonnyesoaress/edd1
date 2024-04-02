#include <stdio.h>
#include <stdlib.h>

void multiplica_vetor_escalar(int v[], int n, int escalar){

    for(int i = 0; i < n; i++){
        v[i] *= escalar;
    }
}

void printa_vetor(int *v, int n){

    for(int i = 0; i < n; i++){
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }

}

int main(){

    int vs[5] = {0, 10, 20, 30, 40};

    puts("VETOR ESTÁTICO");
    printa_vetor(vs, 5);
    puts("");
    multiplica_vetor_escalar(vs, 5, 3);
    printa_vetor(vs, 5);

    int *vh = (int *)calloc(5, sizeof(int));
    for (int i =0; i < 5; i++){
        vh[i] = i * 100;
    }

    puts("VETOR DINAMICO");
    printa_vetor(vh, 5);
    puts("");
    multiplica_vetor_escalar(vh, 5, 3);
    printa_vetor(vh, 5);

    free(vh);
    vh = NULL;

}
