#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdbool.h>


typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

CircNode *Node_create(int val);
void CircNode_destroy(CircNode **cnode_ref);
CircList *List_create();
void CircList_destroy(CircList **L_ref);
bool List_isEmpty(const CircList *L);




#endif