#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "operations.h"
long getRandomValue();

int main() {
    int n;
    int m;
    double m_member;
    double m_insert;
    double m_delete;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter m : ");
    scanf("%d", &m);
    printf("Enter m_member : ");
    scanf("%lf", &m_member);
    printf("Enter m_insert : ");
    scanf("%lf", &m_insert);
    printf("Enter m_delete : ");
    scanf("%lf", &m_delete);

    struct node *linkedList = NULL;
    linkedList = initializedLinkedList(linkedList,n);

//    struct node*curr_p = linkedList;
//    for(int t = 0;t< n;t++){
//        printf("%ld \n",curr_p->data);
//        curr_p = curr_p->next;
//    }
    int num_member = (int)m*m_member;
    int num_insert = (int)m*m_insert;
    int num_delete = (int)m*m_delete;
    for (int i = 0; i < num_member; i++) {
        long randomNumber = getRandomValue();
        if (Member(randomNumber, linkedList)) {
            printf("%ld is a member of the Linked list.\n", randomNumber);
        } else {
            printf("%ld is not a member of the Linked list.\n", randomNumber);
        }}
    for (int i = 0; i < num_insert; i++) {
        long randomNumber = getRandomValue();
        if (Insert(randomNumber, &linkedList)) {
            printf("Inserted %ld in to Linked list.\n", randomNumber);
        } else {
            printf("%ld is already exist in Linked list.\n", randomNumber);
        }}
    for (int i = 0; i < num_delete; i++) {
        long randomNumber = getRandomValue();
        if (Delete(randomNumber, &linkedList)) {
            printf("Deleted %ld from the list.\n", randomNumber);
        } else {
            printf("%ld is not available in the linked list.\n", randomNumber);
        }}

    free(linkedList);
    return 0;
}

/* Helper function to generate random values between 0 and (2^16 - 1)*/
long getRandomValue() {
    return rand() % 65536;
}
