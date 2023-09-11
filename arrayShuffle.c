#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayShuffle.h"

void shuffleArray(int arr[], int size) {
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void*createArray(int*numberList,int m,double m_member,double m_insert,double m_delete){
    for(int r= 0;r < (int)(m*m_member);r++){
        numberList[r] = 0;
    }
    for(int s= 0;s < (int)(m*m_insert);s++){
            numberList[s+(int)(m*m_member)] = 1;
    }
    for(int t= 0;t < (int)(m*m_delete);t++){
            numberList[t+(int)(m*m_member)+(int)(m*m_insert)] = 2;
    }
    return numberList;
}
