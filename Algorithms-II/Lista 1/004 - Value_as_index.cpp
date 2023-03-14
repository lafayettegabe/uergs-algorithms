/* Considere um vetor de trajet?rias de 9 elementos, 
onde cada elemento possui o valor do pr?ximo elemento do vetor a ser lido. */

#include <stdio.h>

int main() {
    int arr[9] = {5, 7, 6, 1, 2, 8, 4, 0, 3}, index = 0;

    for(int i = 0; i < 9; i++) {
        printf("Index: %d, Value: %d \n", index, arr[index]);
        index = arr[index];
    }
}

