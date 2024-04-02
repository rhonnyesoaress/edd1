#include <stdio.h>
#include <stdlib.h>

double aloca_vetor_double(double vet[], int n){

    double *v = (double*)calloc(n, sizeof(double));

    return vet[n];
}

void aloca_vetor_double_referencia(double vet[], int n, double *ret){

    double *ret = (double*)calloc(n, sizeof(double));


}

void desaloca_vetor(int **v){

    free(*v);
    *v = NULL;
}



int main(){

    double vetor[5] = {1, 2, 3, 4, 5};
    double a, b;

    a = aloca_vetor_double(vetor, 5);
    aloca_vetor_double_referencia(vetor, 5, &b);
    desaloca_vetor(&vetor);



    return 0;
}