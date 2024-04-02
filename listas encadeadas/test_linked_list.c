#include "linked_list.h"
#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LinkedList *L = LinkedList_create();

    //puts("");
    //LinkedList_print(L);
    //LinkedList_remove(L, 99);
    //LinkedList_print(L);

    //LinkedList_add_last(L, 10);
    //LinkedList_add_last(L, 2);
    //LinkedList_add_last(L, 4);
    //LinkedList_print(L);

    //puts("Removendo o 10:");
    //LinkedList_remove(L, 10);
    //LinkedList_print(L);

    //puts("Removendo o 2:");
    //LinkedList_remove(L, 2);
    //LinkedList_print(L);

    //puts("Removendo o 4:");
    //LinkedList_remove(L, 4);
    //LinkedList_print(L);

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);

    printf("Size: %d\n", LinkedList_size(L));

    //puts("Removendo o 2:");
    //LinkedList_remove(L, 2);
    //LinkedList_print(L);

    //LinkedList_destroy(&L);
    //printf("L is NULL? %d", L == NULL);
    


    return 0;
}
