/*
Leia uma matriz 4 x 4 e troque os valores da 1?.linha pelos da 4?.coluna, vice-e-versa. Escrever ao final a matriz obtida
*/

#include <stdio.h>

int main() {
    int arr[4][4];

    // fill
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("matriz [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }

    // show
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

	printf("\n");

    // swap
    for(int i = 0; i < 4; i++) {
        int temp = arr[0][i];
        arr[0][i] = arr[i][3];
        arr[i][3] = temp;
    }

    // show
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
