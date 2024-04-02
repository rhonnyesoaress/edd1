#include <stdio.h>
#include <stdlib.h>

int main(){
// 2 fatias, 2 linhas, 2 colunas
    int nslices = 2;
    int nrows = 2;
    int ncollums = 3;
    int m[2][2][3] = {{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int k = 0; k < nslices; k++){
        for(int i = 0; i < nrows; i++){
            for(int j = 0; j < ncollums; j++){
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
        }
    }


    return 0;
}