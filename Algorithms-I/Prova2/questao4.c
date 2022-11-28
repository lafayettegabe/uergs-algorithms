#include <stdio.h>

int media(int idade, int total);
int cadastroIdade();
int cadastroEstado();
void imprima(int media, int casados, int maisNovo);

int main() {
	int idade = 1, estado, maisNovo = 100, casados = 0, solteirosIdade = 0, solteirosTotal = 0;

	printf("\nBem vindo a nossa pesquisa!\nInforme a idade 0 para finalizar.");	
	
	while(idade != 0) {	
		idade = cadastroIdade();
		if(idade != 0) {
			if(idade < maisNovo) {
				maisNovo = idade;
			}
			
			estado = cadastroEstado();
			if(estado = 1) casados++;
			else {
				solteirosIdade += idade;
				solteirosTotal++;
			}
		}
	}
	imprima(media(solteirosIdade, solteirosTotal), casados, maisNovo);
}

void imprima(int media, int casados, int maisNovo) {
	printf("***************\n");
	printf("O mais novo tem: %d anos\n", maisNovo);
	printf("***************\n");
	printf("***************\n");
	printf("O total de casados e: %d\n", casados);
	printf("***************\n");
	printf("***************\n");
	(media > 0) ? printf("Media de idade dos solteiros %d", media) : printf("Ha 0 solteiros.");
}

int media(int idade, int total) {
	if(idade > 0 && total > 0)	
		return idade/total;
	else {
		return 0;
	}
}

int cadastroIdade() {
	int idade = -1;
	while(idade < 0) {
		printf("\nDigite a sua idade: ");
		scanf("%d", &idade);
	}
	return idade;
}

int cadastroEstado() {
	int estado = 0;
	while(estado < 1 || estado > 2) {
		printf("Informe seu estado civil: \n1 - Casado\n2 - Solteiro\n");
		scanf("%d", &estado);
	}
	return estado;
}
