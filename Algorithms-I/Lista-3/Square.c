#include <stdio.h>

int main() {
	int tam = 21; // Pra entrar no primeiro loop.
	while(tam < 0 || tam > 20)
	{
		printf("Digite um tamanho menor que 20: \n");
		scanf("%d", &tam);
	}
	
	for(int i = tam; i > 0 ; i--) // Teto
		printf("* ");
	printf("\n");
	
	for(int i = tam; i > 0 ; i--) // Meio
		{
			printf("*");
			for(int j = tam*2-3; j > 0 ; j--)
				printf(" ");
			printf("*");
			printf("\n");
		}
		
	for(int i = tam; i > 0 ; i--) // Chão
		printf("* ");
	printf("\n");
}
