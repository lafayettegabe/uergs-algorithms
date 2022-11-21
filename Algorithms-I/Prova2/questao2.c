/* em duvida se entendi certo o enunciado dessa */

#include <stdio.h>

void mostrar(char arr[4][4]);

int main() {
	char palavra[4];
	char jogo[4][4] = {{'C', 'C', 'B', 'C'}, {'C', 'A', 'S', 'A'},	{'X', 'F', 'F', 'E'}, {'A', 'E', 'D', 'E'}};
	int count, jogando = 1,	letra[2];
	
	while(jogando) {
		count = 0;
		
		while(count < 4) {
			letra[0] = 0;
			letra[1] = 0;
			
			printf("\n\nBem vindo ao caca-palavras!");
			
			mostrar(jogo);
			
			while((letra[0] < 1 || letra[0] > 4) && (letra[1] < 1 || letra[1] > 4))  {
				printf("\nDigite a linha da letra %d: ", count+1);
				scanf("%d", &letra[0]);
				printf("\nDigite a coluna da letra %d: ", count+1);
				scanf("%d", &letra[1]);
			}
			
			palavra[count++] = jogo[letra[0]-1][letra[1]-1];
		}
		
		if( palavra[0] == 'C' && palavra[1] == 'A' && palavra[2] == 'F' && palavra[3] == 'E') {
			printf("\nParabens! Voce achou a palavra! \nPressione qualquer numero para de tentar novamente.\n");
			jogando = scanf("%d");
		} else {
			printf("\nPuxa... parece que nao era a palavra certa. \nPressione qualquer numero para de tentar novamente.\n");
			jogando = scanf("%d");
		}
	}
}

void mostrar(char arr[4][4]) {
	for(int i = 0; i < 4; i++) {
		printf("\n%c %c %c %c", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
	}
}
