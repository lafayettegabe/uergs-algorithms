/* Crie um vetor de 15 posi��es de inteiros e posteriormente realize a compacta��o dele, 
isto �, elimine as posi��es com valor zero avan�ando uma posi��o, 
com os com os valores subseq�entes do vetor. 
Dessa forma todos �zeros� devem ficar para as posi��es finais do vetor. */

#include <stdio.h>

int main() {
	int arr[15], count = 0;
	
	// L�
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
