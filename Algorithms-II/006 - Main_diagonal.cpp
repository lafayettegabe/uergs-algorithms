/*
Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos. Escreva ao final a matriz obtida.
*/

#include <stdio.h>

int main() {
    int arr[5][5];

    // fill
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == j) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    // show
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
