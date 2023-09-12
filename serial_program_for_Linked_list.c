#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "operations.h"
#include "arrayShuffle.h"
#include <time.h>

long getRandomValue();
void assigningValue();
int n;
int m;
int caseNumber;
int*num;
double m_member;
double m_insert;
double m_delete;
double execution_time;
struct node *linkedList = NULL;

int main() {
    clock_t start_time, end_time;
    caseNumber = 2;
    assigningValue();
    printf("%f num1 \n",m_delete);
    linkedList = initializedLinkedList(linkedList,n);
    num = (int *)malloc(m * sizeof(int));
    createArray(num,m,m_member,m_insert,m_delete);
    shuffleArray(num, m);
    start_time = clock();
    for (int i = 0; i < m; i++) {
        long randomNumber = getRandomValue();
        switch (num[i]) {
            case 0:
                if (Member(randomNumber, linkedList)) {
//                    printf("%ld is a member of the Linked list.\n", randomNumber);
                } else {
//                    printf("%ld is not a member of the Linked list.\n", randomNumber);
                }
                break;
            case 1:
                if (Insert(randomNumber, &linkedList)) {
//                    printf("Inserted %ld in to Linked list.\n", randomNumber);
                } else {
//                    printf("%ld is already exist in Linked list.\n", randomNumber);
                }
                break;
            case 2:
                if (Delete(randomNumber, &linkedList)) {
//                    printf("Deleted %ld from the list.\n", randomNumber);
                } else {
//                    printf("%ld is not available in the linked list.\n", randomNumber);
                }
                break;
        }
    }
    end_time = clock();

    // Calculate the execution time in seconds
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", execution_time);

    free(linkedList);
    free(num);
    return 0;
}

/* Helper function to generate random values between 0 and (2^16 - 1)*/
long getRandomValue() {
    return rand() % 65536;
}
void assigningValue(){
    n = 1000;
    m= 10000;

    switch (caseNumber) {
        case 1:
            m_member=0.99;
            m_insert=0.005;
            m_delete=0.005;
            break;
        case 2:
            m_member=0.90;
            m_insert=0.05;
            m_delete=0.05;
            break;
        case 3:
            m_member=0.5;
            m_insert=0.25;
            m_delete=0.25;
            break;
    }
}
