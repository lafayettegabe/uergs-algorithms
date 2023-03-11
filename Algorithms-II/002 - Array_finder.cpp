/*
Crie um vetor de 20 posições de inteiros.  
Após o vetor estar todo preenchido com valores informados pelo teclado, 
solicite ao usuário a informação de um número, o qual será procurado no vetor. 
Se o valor for encontrado informe em que posição ele se encontra 
(a primeira, caso ele esteja armazenado em mais de uma posição). 
Utilize mensagem adequada para o caso do valor não estar armazenado no vetor.
*/

#include <stdio.h>

int main()
{
    int n, arr[20];

    // Read
    for(int i = 0; i < 20; i++) {
    	printf("Digite o numero da posicao %d: ", i+1);
    	scanf("%d", &arr[i]);
	}
	
	// Find
    printf("Qual numero deseja buscar? ");
    scanf("%d", &n);
    
    for(int i = 0; i <= 20; i++) {
    	if(i == 20)
			printf("O numero nao esta na lista.");
    	else if(n == arr[i]) {
    		printf("%d esta na posicao: %d", n, i+1);
    		break;
		}
	}
}


