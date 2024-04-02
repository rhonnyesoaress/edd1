#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct _stack_node StackNode;
typedef struct _stack Stack;


Stack *Stack_create();
void Stack_destroy(Stack **S_ref);

bool Stack_isEmpty(const Stack *S);
long Stack_size(const Stack *S);

void Stack_push(Stack *S, long val);
int Stack_peek(const Stack *S);
int Stack_pop(Stack *S);

void Stack_print(const Stack *S);

#endif