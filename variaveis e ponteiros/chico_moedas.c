#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char resposta[100]; // aumentei o tamanho para permitir entradas maiores

    puts("\n\n\nMENTIROSO!! VOCE ATACOU CHICO MOEDAS, RAPAZ!");
    
    while (1) {
        printf("\nChico Moedas eh um homem...\n");
        scanf("%s", resposta);

        if (strcmp(resposta, "Integro") == 0) {
            printf("Mais ou menos.\n\n");
        } else if (strcmp(resposta, "Verdadeiro") == 0) {
            printf("Mais ou menos, tambem.\n");
        } else if (strcmp(resposta, "Genteboa") == 0) {
            printf("Verdade.\n");
        } else if (strcmp(resposta, "0") == 0) {
            break; // sair do loop
        } else {
            printf("Fiel.\n");
        }
    }

    return 0;
}
