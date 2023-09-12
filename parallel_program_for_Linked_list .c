#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "operations.h"
#include "arrayShuffle.h"
#include <pthread.h>
#include <time.h>

long getRandomValue();
void *threadFunction(int id);
void assigningValue();
pthread_mutex_t mutex;
pthread_rwlock_t rwlock;
int n;
int m;
int caseNumber;
int numberOfThreads;
int syncType;
int*num;
double m_member;
double m_insert;
double m_delete;
double execution_time;
struct node *linkedList = NULL;

int main() {
    pthread_mutex_init(&mutex, NULL);
    clock_t start_time, end_time;
    caseNumber =0;
    numberOfThreads = 1;
//    syncType = 0 -> Parallel program (based on Pthreads) with one mutex for the entire linked list
//    syncType = 1 -> Parallel program (based on Pthreads) with read-write locks for the entire linked list
    syncType = 1;
    assigningValue();
    linkedList = initializedLinkedList(linkedList, n);
    num = (int *) malloc(m * sizeof(int));
    createArray(num, m, m_member, m_insert, m_delete);
    shuffleArray(num, m);
    pthread_t threads[numberOfThreads];
    start_time = clock();
    for (int i = 0; i < numberOfThreads; i++) {
        pthread_create(&threads[i], NULL, (void *(*)(void *)) threadFunction, (void *) i);
    }

    for (int i = 0; i < numberOfThreads; i++) {
        pthread_join(threads[i], NULL);
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

void * threadFunction(int id){
    for(int r = (int)(m/numberOfThreads)*id;r<(int)(m/numberOfThreads)*(id+1);r++){
        long randomNumber = getRandomValue();
        switch (num[r]) {
            case 0: // Member
                if(syncType == 0){
                    pthread_mutex_lock(&mutex);
                    Member(randomNumber, linkedList);
                    pthread_mutex_unlock(&mutex);
                }
                else if(syncType == 1){
                    pthread_rwlock_wrlock(&rwlock);
                    Member(randomNumber, linkedList);
                    pthread_rwlock_unlock(&rwlock);
                }
                break;
            case 1: // Insert
                if(syncType == 0){
                    pthread_mutex_lock(&mutex);
                    Insert(randomNumber, &linkedList);
                    pthread_mutex_unlock(&mutex);
                }
                else if(syncType == 1){
                    pthread_rwlock_wrlock(&rwlock);
                    Insert(randomNumber, &linkedList);
                    pthread_rwlock_unlock(&rwlock);
                }
                break;
            case 2: // Delete
                if(syncType == 0){
                    pthread_mutex_lock(&mutex);
                    Delete(randomNumber, &linkedList);
                    pthread_mutex_unlock(&mutex);
                }
                else if(syncType == 1){
                    pthread_rwlock_wrlock(&rwlock);
                    Delete(randomNumber, &linkedList);
                    pthread_rwlock_unlock(&rwlock);
                }
                break;
        }}return 0;
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


