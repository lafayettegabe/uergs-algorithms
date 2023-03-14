/*
Crie um vetor de 20 posi��es de inteiros.  
Ap�s o vetor estar todo preenchido com valores informados pelo teclado, 
solicite ao usu�rio a informa��o de um n�mero, o qual ser� procurado no vetor. 
Se o valor for encontrado informe em que posi��o ele se encontra 
(a primeira, caso ele esteja armazenado em mais de uma posi��o). 
Utilize mensagem adequada para o caso do valor n�o estar armazenado no vetor.
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


