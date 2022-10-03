#include <stdio.h>
#define SIZE 7 

int main() {
	int arr[SIZE], c = 0; // Array
	
	for(int i = 0; i < SIZE; i++) { // Read 7 int > 10;
		arr[i] = 0; // Zera a posição i do vetor para entrar na validação de maior que 10.
		while(arr[i] < 10) {
			printf("Digite um numero maior que 10: ");
			scanf("%d", &arr[i]);
			if (arr[i] % 2 != 0) c++; // Se o número lido for lido incrementa o contador em 1 para criar o segundo vetor depois.
		}	
	}
	
	int arr_odd[c]; // Declara o segundo vetor, c = numero de impares no primeiro vetor.
	for(int i = 0, j = 0; i < SIZE; i++) { // Vai olhar todas as posições do primeiro para achar os impares.
		if(arr[i] % 2 != 0) { // Se for impar 
			arr_odd[j] = arr[i]; // Adiciona o valor do impar na posição atual
			j++; // E move pra próxima
		}
	}
	
	for(int i = 0; i < SIZE; i++) { // Printar primeiro vetor. | Numeros maiores que 10
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i < c; i++) { // Printar segundo vetor. | Impares
		printf("%d ", arr_odd[i]);
	}
}
