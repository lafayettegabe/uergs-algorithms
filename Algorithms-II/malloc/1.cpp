/*
Faça um programa que pergunte ao usuário quantos valores ele deseja armazenar em um vetor de doubles, 
depois use a função MALLOC para reservar (alocar) o espaço de memória de acordo com o especificado pelo usuário. 
Use este vetor dinâmico como um vetor comum, atribuindo aos 10 primeiros elementos do vetor valores aleatórios (rand) entre 0 e 100. 
Exiba na tela os valores armazenados nos 10 primeiros elementos do vetor (O vetor deve ter pelo menos um tamanho igual a 10 doubles, ou mais). 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	double *arr;
	int n;
	
	// Lê até o N ser maior ou igual a 10
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	while(n < 10) {
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &n);
	}
	
	// Atribui memória
	arr = (double *) malloc(n * sizeof(double));
	
	// Loopa atribuindo valor aos 10 primeiros e mostra eles na tela.
	for(int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
		printf("%.1f ", arr[i]);
	}
}
