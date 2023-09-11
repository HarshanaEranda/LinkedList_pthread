#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffleArray(int arr[], int size) {
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//int main() {
//    int num[] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9}; // Initialize the array
//    int size = sizeof(num) / sizeof(num[0]);
//
//    printf("Original array: ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", num[i]);
//    }
//
//    shuffleArray(num, size);
//
//    printf("\nShuffled array: ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", num[i]);
//    }
//
//    printf("\n");
//
//    return 0;
//}
