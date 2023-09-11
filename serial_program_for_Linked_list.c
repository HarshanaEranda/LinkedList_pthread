#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "operations.h"
#include "arrayShuffle.h"
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
    int*num;
    linkedList = initializedLinkedList(linkedList,n);
    num = (int *)malloc(m * sizeof(int));
    createArray(num,m,m_member,m_insert,m_delete);
    shuffleArray(num, m);

    for (int i = 0; i < m; i++) {
        long randomNumber = getRandomValue();
        switch (num[i]) {
            case 0:
                if (Member(randomNumber, linkedList)) {
                    printf("%ld is a member of the Linked list.\n", randomNumber);
                } else {
                    printf("%ld is not a member of the Linked list.\n", randomNumber);
                }
                break;
            case 1:
                if (Insert(randomNumber, &linkedList)) {
                    printf("Inserted %ld in to Linked list.\n", randomNumber);
                } else {
                    printf("%ld is already exist in Linked list.\n", randomNumber);
                }
                break;
            case 2:
                if (Delete(randomNumber, &linkedList)) {
                    printf("Deleted %ld from the list.\n", randomNumber);
                } else {
                    printf("%ld is not available in the linked list.\n", randomNumber);
                }
                break;
        }
    }
    free(linkedList);
    free(num);
    return 0;
}

/* Helper function to generate random values between 0 and (2^16 - 1)*/
long getRandomValue() {
    return rand() % 65536;
}
