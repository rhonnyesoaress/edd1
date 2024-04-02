#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct _stack_node{
    int val;
    struct _stack_node *prev;
    struct _stack_node *next;
}StackNode;

typedef struct _stack{
    StackNode *begin;
    StackNode *end;
    size_t size;
}Stack;

StackNode *StackNode_create(int val){
    StackNode *stacknode = (StackNode*)calloc(1, sizeof(StackNode));

    stacknode->val = val;
    stacknode->next = NULL;
    stacknode->prev = NULL;


    return stacknode;
}

Stack *Stack_create(){
    Stack *S = (Stack*)calloc(1, sizeof(Stack));

    S->begin = NULL;
    S->end = NULL;
    S->size = 0;

    return S;
}

void Stack_destroy(Stack **S_ref){

    Stack *S = *S_ref;
    StackNode *p = S->begin;
    StackNode *aux = NULL;

    while (p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(S);
    *S_ref = NULL;

}

bool Stack_isEmpty(const Stack *S){
    if(S->begin == NULL && S->end == NULL){
        return true;
    }else{
        return false;
    }
}

long Stack_size(const Stack *S){
    return S->size;
}

void Stack_push(Stack *S, long val){
    StackNode *q = StackNode_create(val);

    if(Stack_isEmpty(S)){
        S->begin = q;
        S->end = q;
        S->size++;
    }else{
        S->end->next = q;
        q->prev = S->end;
        S->end = S->end->next;
        S->size++;
    }
}

int Stack_peek(const Stack *S){

    if(Stack_isEmpty(S)){
        fprintf(stderr, "ERROR in 'Stack_peek'\n");
        fprintf(stderr, "Empty Stack'\n");
        exit(EXIT_FAILURE);
    }else{
        return S->end->val;
    }
}

int Stack_pop(Stack *S){
    if(Stack_isEmpty(S)){
        fprintf(stderr, "ERROR in 'Stack_pop'\n");
        fprintf(stderr, "Empty Stack'\n");
        exit(EXIT_FAILURE);
    }else{

        int retired_element = S->end->val;

        S->end = S->end->prev;
        S->end->next = NULL;
        S->size--;

        return retired_element;
    }

}

void Stack_print(const Stack *S){

    StackNode *p = S->begin;

    while(p != NULL){
        printf("%d, ", p->val);
        p = p->next;
    }
}