#include <stdio.h>
#include <stdlib.h>

int **create_int_matrix(size_t n_rows, size_t n_collums){

    int **m = NULL;

    m = (int**)calloc(n_rows, sizeof(int*));

    for(int i = 0; i < n_rows; i++){
        m[i] = (int*)calloc(n_collums, sizeof(int));
    }

    return m;
}

void print_int_matrix(const int**m, int n_rows, int n_collums){

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_collums; j++){
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
    }
}

void add_scalar_into_int_matrix(int **m, int n_rows, int n_collums, int scalar){

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_collums; j++){
            m[i][j] += scalar;
        }
    }
}

void destroy_int_matrix(int ***m, int n_rows){

    int **aux = *m;

    for(int i = 0; i < n_rows; i++){
        free(aux[i]);
    }
    free(aux);
    *m = NULL;
}

int main(int argc, char **argv){

    if(argc != 4){
        printf("ERROR\n %s nrows ncols scalar", argv[0]);
    }

    int n_rows = atoi(argv[1]);
    int n_collums = atoi(argv[2]);
    int scalar = atoi(argv[3]);
    int **m = NULL;

    // alocação da matriz
    m = create_int_matrix(n_rows, n_collums);

    // atribuição de valores a matriz

    int count = 0;

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_collums; j++){
            m[i][j] = count++;
        }
    }

    print_int_matrix((const int**)m, n_rows, n_collums);

    add_scalar_into_int_matrix(m, n_rows, n_collums, scalar);

    print_int_matrix((const int**)m, n_rows, n_collums);

    destroy_int_matrix(&m, n_rows);

    printf("m == NULL? %d", m == NULL);



    return 0;
}