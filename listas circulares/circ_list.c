#include "circ_list.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _circ_node{
    int val;
    struct _circ_node *next;
    struct _circ_node *prev;
}CircNode;

typedef struct _circ_list{
    CircNode *begin;
    CircNode *end;
    size_t size;
}CircList;

CircNode *CircNode_create(int val){

    CircNode *cnode = (CircNode*)calloc(1, sizeof(CircNode));

    cnode->next = cnode;
    cnode->prev = cnode;
    cnode->val = val;

    return cnode;

}

void CircNode_destroy(CircNode **cnode_ref){

    CircNode *cnode = *cnode_ref;
    free(cnode);
    *cnode_ref = NULL;
}

CircList *CircList_create(){

    CircList *L = (CircList*)calloc(1, sizeof(CircList));

    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void CircList_destroy(CircList **L_ref){

    CircList *L = *L_ref;

    CircNode *aux = NULL;
    CircNode *p = L->begin;

    while(p != L->end){
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }
    CircNode_destroy(&p);
    free(L);
    *L_ref = NULL;
}

bool CircList_isEmpty(const CircList *L){

    if(L->size == 0){
        return true;
    }else{
        return false;
    }
}