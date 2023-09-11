#ifndef LAB_ASSIGNMENT_OPERATIONS_H
#define LAB_ASSIGNMENT_OPERATIONS_H
#include "node.h"

struct node * initializedLinkedList(struct node * linkedList,int n);
int Member(long value,  struct node *head_p);
int Insert(long value, struct node **head_p);
int Delete(long value, struct node **head_p);
#endif //LAB_ASSIGNMENT_OPERATIONS_H
