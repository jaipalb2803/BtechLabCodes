#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int* generateArray(int n) {
    // dynamically creating an array of required size
    int* array = (int*)malloc(n * sizeof(int));
    int i; 
    srand(time(0)); 
    for (i = 0; i < n; i++) {
        array[i] = rand()%100; // random number between 0 - 100 
    }
    return array;
}

void main() {
    int i , n = 10;
    int* arr = generateArray(n);
    
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
        // or printf("%d", arr[i]);
    }
}

