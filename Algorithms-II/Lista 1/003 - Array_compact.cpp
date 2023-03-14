/* Crie um vetor de 15 posições de inteiros e posteriormente realize a compactação dele, 
isto é, elimine as posições com valor zero avançando uma posição, 
com os com os valores subseqüentes do vetor. 
Dessa forma todos “zeros” devem ficar para as posições finais do vetor. */

#include <stdio.h>

int main() {
	int arr[15], count = 0;
	
	// Lê
	for(int i = 0; i < 15; i++) {
		printf("Digite o valor na posicao %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	// Compact
	for(int i = 0; i < 15; i++) {
		if(arr[i] != 0)
			arr[count++] = arr[i];
	}

	// Fill zeros
	for(int i = count; i < 15; i++) {
		arr[i] = 0;
	}
	
	// Show
	for(int i = 0; i < 15; i++) {
		printf("%d ", arr[i]);
	}
	
}
