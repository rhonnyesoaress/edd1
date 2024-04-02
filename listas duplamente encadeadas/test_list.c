#include "list.c"
#include <stdio.h>

int main(){

    List *L = List_create();

    //List_add_first(L, 7);
    //List_add_first(L, 4);
    //List_add_first(L, 2);
    //List_add_first(L, 10);
    //List_print(L);
    //List_inverted_print(L);

    List_add_last(L, 10);
    List_add_last(L, 2);
    List_add_last(L, 4);
    List_add_last(L, 7);
    List_print(L);
    //List_inverted_print(L);
    puts("Removendo o 10...");
    List_remove(L, 10);
    List_print(L);

    puts("Removendo o 2...");
    List_remove(L, 2);
    List_print(L);

    puts("Removendo o 4...");
    List_remove(L, 4);
    List_print(L);
    
    puts("Removendo o 7...");
    List_remove(L, 7);
    List_print(L);

    List_destroy(&L);

    return 0;
}