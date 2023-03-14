/*
Crie uma matriz  5 x 5 de inteiros e posteriormente (após o preenchimentos dos elementos via teclado), escreva a localização (linha e a coluna) do maior valor.
*/

#include <stdio.h>

int main() {
    int arr[5][5], max = 0, max_i = 0, max_j = 0;

    // fill
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
        	printf("Digite o valor da linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
            if(arr[i][j] > max) {
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // show  
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n\n");
    }

    // find max
    printf("O maior valor e %d, na linha %d e coluna %d", max, max_i+1, max_j+1);
}
