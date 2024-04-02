#include "static_queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _static_queue{
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
}StaticQueue;

StaticQueue *StaticQueue_create(long capacity){

    StaticQueue *Q = (StaticQueue*)calloc(1, sizeof(StaticQueue));

    Q->capacity = capacity;
    Q->data = (int*)calloc(Q->capacity, sizeof(int));
    Q->begin = 0;
    Q->end = 0;
    Q->size = 0;

    return Q;
}

void StaticQueue_destroy(StaticQueue **Q_ref){

    StaticQueue *Q = *Q_ref;

    free(Q->data);
    free(Q);

    *Q_ref = NULL;
}

bool StaticQueue_isEmpty(const StaticQueue *Q){
    if(Q->size == 0){
        return true;
    }else{
        return false;
    }
}

bool StaticQueue_isFull(const StaticQueue *Q){
    if(Q->size == Q->capacity){
        return true;
    }else{
        return false;
    }
}

long StaticQueue_size(const StaticQueue *Q){
    return Q->size;
}

void StaticQueue_enqueue(StaticQueue *Q, int val){

    if(StaticQueue_isFull(Q)){
    fprintf(stderr, "ERROR in 'StaticQueue_enqueue'.\n");
    fprintf(stderr, "Queue is full.\n");
    exit(EXIT_FAILURE);
    }

    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
}

int StaticQueue_peek(const StaticQueue *Q){

    if(StaticQueue_isEmpty(Q)){
        fprintf(stderr, "ERROR in 'StaticQueue_peek'.\n");
        fprintf(stderr, "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue *Q){

    if(StaticQueue_isEmpty(Q)){
        fprintf(stderr, "ERROR in 'StaticQueue_dequeue'.\n");
        fprintf(stderr, "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return val;
    
}

void StaticQueue_print(const StaticQueue *Q) {
    printf("capacity: %ld\n", Q->capacity);
    printf("size: %ld\n", Q->size);
    printf("begin: %ld\n", Q->begin);
    printf("end: %ld\n\n", Q->end);

    long s, i;

    for (s = 0, i = Q->begin;
         s < Q->size;
         s++, i = (i + 1) % Q->capacity) {
        printf("%d, ", Q->data[i]);
    }
    puts("");
}