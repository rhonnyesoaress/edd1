#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct _queue_node QueueNode;
typedef struct _queue Queue;

QueueNode *QueueNode_create(int val);
Queue *Queue_create();
void Queue_destroy(Queue **Q_ref);

bool Queue_isEmpty(const Queue *Q);
bool Queue_size(const Queue *Q);

void Queue_enqueue(Queue *Q, int val);
int Queue_peek(const Queue *Q);
int Queue_dequeue(Queue *Q);




#endif