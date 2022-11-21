#include <stdio.h>
#define QTD 5


int cadastro(int c, int i);
void pesoTotal(int m[QTD][3]);
int pQuilo();

int main() {
	int quilo, bois[QTD][3];
	
	for(int i = 0; i < QTD; i++) {
		bois[i][0] = cadastro(0, i+1);
		bois[i][1] = cadastro(1, i+1);
	}
	
	pesoTotal(bois);
	quilo = pQuilo();
	
	for(int i = 0; i < QTD; i++) {
		bois[i][2] = bois[i][1] * quilo;
		printf("\nO preco de venda do boi %d e: %d", i+1, bois[i][2]);
	}
}

int cadastro(int c, int i) {
	
	int input = 0;
	
	if(!c) {
		while(input <= 0) {
			printf("\nInforme o peso do boi %d: ", i);
			scanf("%d", &input);
		}
	} else {
		while(input <= 0) {
			printf("\nInforme o preco de compra do boi %d: ", i);
			scanf("%d", &input);
		}
	}
	
	return input;
}

void pesoTotal(int m[QTD][3]) {
	int acumulador = 0;
	
	for(int i = 0; i < QTD; i++) {
		acumulador += m[i][1];
	}
	
	printf("\nO peso total da carga e: %d", acumulador);
}

int pQuilo() {
	int quilo = 0;
	
	while(quilo <= 0) {
		printf("\nInforme o valor do quilo no dia de hoje: ");
		scanf("%d", &quilo);
	}
	
	return quilo;
}
