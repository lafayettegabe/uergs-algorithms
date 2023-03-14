/*Leia duas matrizes 4 x 4 e escreva uma terceira com os maiores elementos entre as primeiras*/

#include <stdio.h>

int main() {
    int arr1[4][4], arr2[4][4], arr3[4][4];

    // fill arr1
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("primeira matriz [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    // fill arr2
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("segunda matriz [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    // fill arr3
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(arr1[i][j] > arr2[i][j]) {
                arr3[i][j] = arr1[i][j];
            } else {
                arr3[i][j] = arr2[i][j];
            }
        }
    }

    // show
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}
