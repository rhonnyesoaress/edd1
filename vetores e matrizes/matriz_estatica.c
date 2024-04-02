#include <stdio.h>
#include <stdlib.h>

int main(){

    int n_rows = 2;
    int n_collums = 3;
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_collums; j++){
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
    }


    return 0;
}