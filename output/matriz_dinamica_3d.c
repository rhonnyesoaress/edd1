#include <stdio.h>
#include <stdlib.h>

int main(){

    int n_slices = 2;
    int n_rows = 2;
    int n_collums = 3;

    int ***m = (int***)calloc(n_slices, sizeof(int **));

    printf("\n&m = %p, m = %p\n\n", &m, m);

    // para cada fatia
    for(int k = 0; k < n_slices; k++){
        m[k] = (int**)calloc(n_rows, sizeof(int*));
        // para cada linha
        for(int i =0; i < n_rows; i++){
            m[k][i] = (int*) calloc(n_collums, sizeof(int));
        }
    }

        int count = 0;

        for(int k = 0; k < n_slices; k++){
            printf("&m[%d] = %p, m[%d] = %p\n", k, &m[k], k, m[k]);
            for(int i = 0; i < n_rows; i++){
                printf("&m[%d][%d] = %p, m[%d][%d] = %p\n", k, i, &m[k][i], k, i, m[k][i]);
                for(int j = 0; j < n_collums; j++){
                    m[k][i][j] = count++;
                    printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
            puts("");
        }
        puts("");

    }

    // FALTA DESALOCAR A MATRIZ DINAMICA
    return 0;
}