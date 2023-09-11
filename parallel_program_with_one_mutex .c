#include <stdio.h>
#include <stdlib.h>
#include "node.h"

long getRandomValue();

int main() {
    int n;
    int m;
    int m_member;
    int m_insert;
    int m_delete;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter m : ");
    scanf("%d", &m);
    printf("Enter m_member : ");
    scanf("%d", &m_member);
    printf("Enter m_insert : ");
    scanf("%d", &m_insert);
    printf("Enter m_delete : ");
    scanf("%d", &m_delete);
    struct node *linkedList = NULL;

    for (int i = 0; i < 1000; i++) {
        long randomNumber = getRandomValue();
        int operation = i % 3;
        switch (operation) {
            case 0: // Member
                if (Member(randomNumber, linkedList)) {
                    printf("%ld is a member of the Linked list.\n", randomNumber);
                } else {
                    printf("%ld is not a member of the Linked list.\n", randomNumber);
                }
                break;
            case 1: // Insert
                if (Insert(randomNumber, &linkedList)) {
                    printf("Inserted %ld into the list.\n", randomNumber);
                } else {
                    printf("%ld is already exist in the linked list", randomNumber);
                }
                break;
            case 2: // Delete
                if (Delete(randomNumber, &linkedList)) {
                    printf("Deleted %ld from the list.\n", randomNumber);
                } else {
                    printf("ld% is not available in the linked list", randomNumber);
                }
                break;
        }
    }
    free(linkedList);
    return 0;
}

/* Helper function to generate random values between 0 and (2^16 - 1)*/
long getRandomValue() {
    return rand() % 65536;
}
