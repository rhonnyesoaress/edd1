#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _simple_node{
    int val;
    struct _simple_node *next;
}SNode;


typedef struct _linked_list{
    SNode *begin;
    SNode *end;
    size_t size;
}LinkedList;

SNode *SNode_create(int val){
    SNode *snode = (SNode*)calloc(1, sizeof(SNode));

    snode->val = val;
    snode->next = NULL;

    return snode;
}

bool LinkedList_isEmpty(const LinkedList *L){
    if(L->size == 0){
        return true;
    }else{
        return false;
    }
}

LinkedList *LinkedList_create(){

    LinkedList *L = (LinkedList*)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void LinkedList_destroy(LinkedList **L_ref){
    LinkedList *L = *L_ref;

    SNode *pos = L->begin;
    SNode *prev = NULL;

    while(pos != NULL){
        prev = pos;
        pos = pos->next;
        free(prev);
    }

    free(L);
    *L_ref = NULL;


}

//void LinkedList_add_first(LinkedList *L, int val){

//    SNode *p = SNode_create(val);
//    p->next = L->begin;
//    L->begin = p;
//}

void LinkedList_add_first(LinkedList *L, int val){

    SNode *p = SNode_create(val);
    p->next = L->begin;

    if(LinkedList_isEmpty(L)){
        L->end = p;
    }
    
    L->begin = p;
    L->size++;
}

void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *q = SNode_create(val); // no que guarda o valor a ser inserido.

    // se a lista estiver vazia, a caixinha begin inicial aponta para o novo no.
    if(LinkedList_isEmpty(L)){
        L->begin = q;
    }else{
        SNode *p = L->begin;
        // enquanto o ponteiro criado para percorrer nao encontrar o ultimo no, ele vai apontando para o proximo.
        while(p->next != NULL){
            p = p->next;
        }
        // apos ele encontrar o ultimo no, ele insere o novo ultimo no.
        p->next = q;
    }
    L->size++;
}
void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = SNode_create(val);

    if(LinkedList_isEmpty(L)){
        L->begin = q;
        L->end = q;
    }else{
        L->end->next = q;
        L->end = L->end->next;
    }
    L->size++;
}

void LinkedList_print(const LinkedList *L){

    SNode *p = L->begin;

    printf("Size: %d\n", L->size);
    printf("L -> ");
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL");

    if(L->end == NULL){
        printf("\nL->end = NULL\n");
    }else{
        printf("\nL->end = %d\n", L->end->val);
    }
    printf("Size: %d\n", L->size);
    puts("");
}

void LinkedList_remove_v1(LinkedList *L, int val){

    if(!LinkedList_isEmpty(L)){
        //caso 1 - o elemento está na cabeça da lista.
        SNode *pos = L->begin;
        if(L->begin->val == val){
            if(L->begin == L->end){
                L->end = NULL;
            }
            L->begin = L->begin->next;
            free(pos);
            L->size--;
        }else{
            //caso 2 - o elemento está no meio
            //caso 3 - o elemento está na cauda.
            SNode *prev = L->begin;
            SNode *pos = L->begin->next;

            while (pos != NULL && pos->val != val){
                prev = prev->next;
                pos = pos->next;
            }
            if(pos != NULL){
                prev->next = pos->next;

                if(pos->next == NULL){
                    L->end = prev;
                }
                free(pos);
                L->size--;
            }
        }
    }
}

void LinkedList_remove(LinkedList *L, int val){
    if(!LinkedList_isEmpty(L)){
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while(pos != NULL && pos->val != val){
            prev = pos;
            pos = pos->next;
        }

        if(pos != NULL){
            if(L->end == pos){
                L->end = prev;
            }
            if(L->begin == pos){
                L->begin = L->begin->next;
            }else{
                prev->next = pos->next;
            }

            free(pos);
            L->size--;
        }
    }

}

//numero mt grande sem sinal, q tem como flag %d.

size_t LinkedList_size_slow(const LinkedList *L){
    size_t count = 0;
    SNode *p = L->begin;

    while(p != NULL){
        count++;
        p = p->next;
    }
    
    return count;
}

size_t LinkedList_size(const LinkedList *L){
    return L->size;
}

int LinkedList_first_val(const LinkedList *L){
    if(!LinkedList_isEmpty(L)){
        return L->begin->val;
    }else{
        fprintf(stderr, "ERROR\n");
        fprintf(stderr, "Empty List.\n");
        exit(EXIT_FAILURE);
    }

}

int LinkedList_last_val(const LinkedList *L){

    if(!LinkedList_isEmpty(L)){
        return L->end->val;
    }else{
        fprintf(stderr, "ERROR\n");
        fprintf(stderr, "Empty List.\n");
        exit(EXIT_FAILURE);
    }

}


int LinkedList_get_val(const LinkedList *L, int index){
    if(LinkedList_isEmpty(L)){
        fprintf(stderr, "ERROR in 'get_val'\n");
        fprintf(stderr, "Empty List.\n");
        exit(EXIT_FAILURE);

    }else if(index < 0 || index >= L->size){
        fprintf(stderr, "ERROR in 'get_val'\n");
        fprintf(stderr, "Invalid index.\n");
        exit(EXIT_FAILURE);
    }else{
        int i = 0;
        SNode *p = L->begin;

        while(i != index){
            p = p->next;
            i++;
        }

        return p->val;
    }

}




