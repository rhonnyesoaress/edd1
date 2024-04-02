#include "static_stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_stack{
    int *data;
    long capacity;
    long top;

}StaticStack;

StaticStack *StaticStack_create(size_t capacity){

    StaticStack *S = (StaticStack*)calloc(1, sizeof(StaticStack));

    S->capacity = capacity;
    S->top = -1;
    S->data = (int*)calloc(S->capacity, sizeof(int));

    return S;
}

void StaticStack_destroy(StaticStack **S_ref){

    StaticStack *S = *S_ref;

    free(S->data);
    free(S);
    *S_ref = NULL;

}

bool StaticStack_isEmpty(const StaticStack *S){

    if(S->top == -1){
        return true;
    }else{
        return false;
    }

}

bool StaticStack_isFull(const StaticStack *S){

    if(S->top == (S->capacity-1)){
        return true;
    }else{
        return false;
    }

}

long StaticStack_size(const StaticStack *S){
    return S->top + 1;
}

void StaticStack_push(StaticStack *S, int val){

    if(StaticStack_isFull(S)){
        fprintf(stderr, "ERROR in 'StaticStack_push'.\n");
        fprintf(stderr, "Stack is full.\n");
        exit(EXIT_FAILURE);
    }

    S->top++;   
    S->data[S->top] = val;

}

int StaticStack_peek(const StaticStack *S){

    if(StaticStack_isEmpty(S)){
        fprintf(stderr, "ERROR in 'StaticStack_peek'.\n");
        fprintf(stderr, "Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return S->data[S->top];
}

int StaticStack_pop(StaticStack *S){

    if(StaticStack_isEmpty(S)){
        fprintf(stderr, "ERROR in 'StaticStack_pop'.\n");
        fprintf(stderr, "Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    int x = S->data[S->top];
    S->top--;
    
    return x;

}

void StaticStack_print(const StaticStack *S){

    printf("Capacity: %ld\n", S->capacity);
    printf("Top: %ld\n", S->top);

    for(long i = 0; i <= S->top; i++){
        printf("%d, ", S->data[i]);
    }

    puts("");

}