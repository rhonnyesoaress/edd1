#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> //biblioteca do size_t

typedef struct _doubly_node{
    int val;
    struct _doubly_node *next;
    struct _doubly_node *prev;
}DoublyNode, Node;

typedef struct _doubly_linked_list{
    Node *begin;
    Node *end;
    size_t size;
}DoublyLinkedList, List;

Node *Node_create(int val){

    Node *node = (Node*)calloc(1, sizeof(Node));

    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;

}

List *List_create(){

    List *L = (List*)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void List_destroy(List **L_ref){

    List *L = *L_ref;

    Node *pos = L->begin;
    Node *aux = NULL;

    while(pos != NULL){
        aux = pos;
        pos = pos->next;
        free(aux);
    }
    free(L);
    *L_ref = NULL;

}

bool List_isEmpty(const List *L){
    if(L->size == 0){
        return true;
    }else{
        return false;
    }
}

void List_add_first(List *L, int val){

    Node *q = Node_create(val);

    if(List_isEmpty(L)){
        
        L->end = q;
    }else{
        q->next = L->begin;
        L->begin->prev = q;
        
    }
    L->begin = q;
    L->size++;

}

void List_print(const List *L){

    Node *p = L->begin;

    printf("L -> ");
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL");
    puts("");
    if(L->end == NULL){
        printf("L->end = NULL\n");
    }else{
        printf("L->end = %d\n", L->end->val);
    }
    printf("Size: %d\n", L->size);
    puts("");
}

void List_inverted_print(const List *L){
    Node *p = L->end;

    printf("L->end -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->prev;
    }
    printf("NULL");
    puts("");
    if(L->end == NULL){
        printf("L->begin = NULL\n");
    }else{
        printf("L->begin = %d\n", L->begin->val);
    }
    puts("");
}

void List_add_last(List *L, int val){
    Node *q = Node_create(val);

    if(List_isEmpty(L)){
        L->begin = q;

    }else{
        L->end->next = q;
        q->prev = L->end;
        
        
    }
    L->end = q;
    L->size++;
}

void List_remove(List *L, int val) {
    if (!List_isEmpty(L)) {
        Node *p = L->begin;

        // caso 1: o elemento está na cabeça da lista
        if (L->begin->val == val) {
            L->begin = p->next;
            
            // a lista possui apenas um único elemento
            if (L->end == p) {
                L->end = NULL;
            }
            // a lista possui mais de um elemento
            else {
                L->begin->prev = NULL;
            }
            
            free(p);
            L->size--;
        }
        // caso 2: o elemento está no meio da lista
        // caso 3: o elemento está no final da lista
        else {
            p = p->next;

            while (p != NULL) {
                if (p->val == val) {
                    p->prev->next = p->next;
                    
                    // caso 3
                    if (L->end == p) {
                        L->end = p->prev;
                    }
                    // caso 2
                    else {
                        p->next->prev = p->prev;
                    }

                    free(p);
                    p = NULL;
                    L->size--;
                }
                else {
                    p = p->next;
                }
            }
        }
    }
}