#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h> // biblioteca do size_t.

typedef struct _simple_node SNode;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
SNode *SNode_create(int val);
void LinkedList_destroy(LinkedList **L_ref);
bool LinkedList_isEmpty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
//remove o primeiro elemento encontrado q possua o valor val.
void LinkedList_remove_v1(LinkedList *L, int val);
void LinkedList_remove(LinkedList *L, int val);
size_t LinkedList_size_slow(const LinkedList *L);
size_t LinkedList_size(const LinkedList *L);
int LinkedList_first_val(const LinkedList *L);
int LinkedList_last_val(const LinkedList *L);
int LinkedList_get_val(const LinkedList *L, int index);

#endif