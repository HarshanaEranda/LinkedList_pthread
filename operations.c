#include <stdlib.h>
#include "node.h"
#include "operations.h"


struct node * initializedLinkedList(struct node * linkedList,int n) {
    for (int r = 0; r < n; r++) {
        long randomNumber = rand() % 65536;
        Insert(randomNumber, &linkedList);
    }
    return linkedList;
}
int Member(long value,  struct node *head_p) {
    struct node *current_p = head_p;
    while (current_p != NULL && current_p->data < value)
        current_p = current_p->next;
    if (current_p == NULL || current_p->data > value) {
        return 0; /* Not a member */
    } else {
        return 1; /* A member */
    }

}
int Insert(long value, struct node **head_p) {
    struct node *current_p = *head_p;
    struct node *previous_p = NULL;
    struct node *temporary_p;

    while (current_p != NULL && current_p->data < value) {
        previous_p = current_p;
        current_p = current_p->next;
    }
    if (current_p == NULL || current_p->data > value) {
        temporary_p = malloc(sizeof(struct node));
        temporary_p->data = value;
        temporary_p->next = current_p;
        if (previous_p == NULL) /* New first value */
            *head_p = temporary_p;
        else
            previous_p->next = temporary_p;
        return 1;
    } else { /* Value already in the list*/
        return 0;
    }
}
int Delete(long value, struct node **head_p) {
    struct node *current_p = *head_p;
    struct node *previous_p = NULL;

    while (current_p != NULL && current_p->data < value) {
        previous_p = current_p;
        current_p = current_p->next;
    }
    if (current_p != NULL && current_p->data == value) {
        if (previous_p == NULL) {
            *head_p = current_p->next;
            free(current_p);
        } else {
            previous_p->next = current_p->next;
            free(current_p);
        }
        return 1;
    } else {
        return 0;
    }
}
