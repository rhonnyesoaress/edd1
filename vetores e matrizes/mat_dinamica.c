#include <stdio.h>
#include <stdlib.h>

int main(){

    int n_rows = 2;
    int n_collums = 3;
    int **m = NULL;

    m = (int**)calloc(n_rows, sizeof(int*));

    for(int i = 0; i < n_rows; i++){
        m[i] = (int*)calloc(n_collums, sizeof(int));
    }

    int count = 0;

    printf("&m = %p, m = %p\n", &m, m);

    for(int i = 0; i < n_rows; i++){
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
        for(int j = 0; j < n_collums; j++){
            m[i][j] = count;
            count++;
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
    }
    puts("");


    return 0;
}
