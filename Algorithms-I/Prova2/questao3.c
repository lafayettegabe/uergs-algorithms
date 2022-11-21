#include <stdio.h>

int par();
int impar();

int main() {
	int acumulador = 0, pares[5], impares[5];
	
	for(int i = 0; i < 5; i++) {
		pares[i] = par();
	}
	
	for(int i = 0; i < 5; i++) {
		impares[i] = impar();
	}
	
	int matriz[5][2];
	for(int i = 0; i < 5; i++) {
		matriz[i][0] = pares[i];
		matriz[i][1] = impares[i];
		
		acumulador += matriz[i][0] + matriz[i][1];
	}
	
	printf("A soma de todos os elementos da matriz e: %d", acumulador);
}

int par() {
	int n = 0;
	
	while(n == 0 && n / 2 != 0) {
		printf("Digite um numero par: ");
		scanf("%d", &n);
	}
	
	return n;
}

int impar() {
	int n = 0;
	
	while(n == 0 && n / 2 == 0) {
		printf("Digite um numero impar: ");
		scanf("%d", &n);
	}
	
	return n;
}
