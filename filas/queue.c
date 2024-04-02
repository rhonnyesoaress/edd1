#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _queue_node{
    int val;
    struct _queue_node *prev;
    struct _queue_node *next;
}QueueNode;

typedef struct _queue{
    
    QueueNode *begin;
    QueueNode *end;
    size_t size;

}Queue;

QueueNode *QueueNode_create(int val){

    QueueNode *queuenode = (QueueNode*)calloc(1, sizeof(QueueNode));

    queuenode->val = val;
    queuenode->next = NULL;
    queuenode->prev = NULL;

    return queuenode;
}

Queue *Queue_create(){

    Queue *Q =(Queue*)calloc(1, sizeof(Queue));

    Q->begin = NULL;
    Q->end = NULL;
    Q->size = 0;

    return Q;
}

void Queue_destroy(Queue **Q_ref){

    Queue *Q = *Q_ref;
    QueueNode *p = Q->begin;
    QueueNode *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(Q);
    *Q_ref = NULL;
}

bool Queue_isEmpty(const Queue *Q){
    if(Q->size == 0){
        return true;
    }else{
        return false;
    }
}

bool Queue_size(const Queue *Q){

    return Q->size;
}

void Queue_enqueue(Queue *Q, int val){

    QueueNode *novo_no = QueueNode_create(val);

    if(Queue_isEmpty(Q)){
        Q->begin = novo_no;
        Q->end = novo_no;
        Q->size++;
    }else{
        Q->end->next = novo_no;
        novo_no->prev = Q->end;
        Q->end = Q->end->next;
        Q->size++;
    }
}

int Queue_peek(const Queue *Q){

    if(Queue_isEmpty(Q)){
        fprintf(stderr, "ERROR in 'Queue_peek'.\n");
        fprintf(stderr, "Queue is empty.'\n");
        exit(EXIT_FAILURE);
    }
    
    return Q->begin->val;
    
}

int Queue_dequeue(Queue *Q){

    if(Queue_isEmpty(Q)){
        fprintf(stderr, "ERROR in 'Queue_dequeue'.\n");
        fprintf(stderr, "Queue is empty.'\n");
        exit(EXIT_FAILURE);
    }
    int aux = Q->begin->val;
    Q->begin = Q->begin->next;
    Q->size--;
    return aux;

}

void Queue_print(const Queue *Q){

    QueueNode *p = Q->begin;

    while(p != NULL){
        printf("%d, ", p->val);
        p = p->next;
    }
}