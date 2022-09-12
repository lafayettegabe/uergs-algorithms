/*
4) Escrever um algoritmo que leia uma quantidade desconhecida de números e conte quantos deles estão nos seguintes intervalos: 
[0-25], [26-50], [51-75] e [76-100]. 
A entrada de dados deve terminar quando for lido um número negativo.
*/
#include <stdio.h>

int main() {
	int i0_25 = 0, i26_50 = 0, i51_75 = 0, i76_100 = 0, i = 0;
	while(i >= 0)
	{
		printf("Digite um numero: ");
		scanf("%d", &i);
		if(i >= 0 && i <= 25) i0_25++;
		else if(i <= 50) i26_50++;
		else if(i <= 75) i51_75++;
		else if(i <= 100) i76_100++;
	}
	printf("\n\nForam digitados: \n%d numeros no intervalo 0-25 \n%d numeros no intervalo 26-50 \n%d numeros no intervalo 51-75 \n%d numeros no intervalo 76-100\n",  i0_25, i26_50, i51_75, i76_100);
}
