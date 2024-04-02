#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(size_t capacity);
void StaticStack_destroy(StaticStack **S_ref);

bool StaticStack_isEmpty(const StaticStack *S);
bool StaticStack_isFull(const StaticStack *S);
long StaticStack_size(const StaticStack *S);

void StaticStack_push(StaticStack *S, int val);
int StaticStack_peek(const StaticStack *S);
int StaticStack_pop(StaticStack *S);

void StaticStack_print(const StaticStack *S);

#endif