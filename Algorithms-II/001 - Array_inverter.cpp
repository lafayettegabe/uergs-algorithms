/*  Crie um vetor de 16 posições de inteiros (receba os valores pelo teclado para serem armazenados). 
    Posteriormente, troque os 8 primeiros valores pelos 8 últimos e vice-e-versa. 
    Escreva ao final o vetor obtido.
*/

#include <stdio.h>

void mostrar(int arr);
void inveter(int arr);

int main() {
	int arr[16], temp;
	
	// Recebe a array
	for(int i = 0; i < 15; i++) {
		printf("Digita a posicao %d do vetor: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	mostrar(arr);
	
	inveter(arr);
	
	mostrar(arr);
}

void mostrar(int arr) {	
	// Mostra a array
	for(int i = 0; i < 15, i++) {
		printf("%d", arr[i])		
	}
	print("\n");
}

void inverter(int arr) {
	
	for(int i = 0; i < 8; i++) {
		temp      = arr[i];
		arr[i]    = arr[16-i];
		arr[16-i] = temp;
	}
	
	print("\n");
}
