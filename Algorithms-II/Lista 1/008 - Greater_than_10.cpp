/*
Leia uma matriz 6 x 6, conte e escreva quantos valores maiores que 10 ela possui.
*/

#include <stdio.h>

int main() {
    int arr[6][6], count = 0;

    // fill
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            printf("matriz [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);

            // count
            if(arr[i][j] > 10) {
                count++;
        	}
        }
    }

    // show
    printf("Ha %d maiores que 10.", count);
}
