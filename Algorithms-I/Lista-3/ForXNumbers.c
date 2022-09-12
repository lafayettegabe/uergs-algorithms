#include <stdio.h>

/*
3) Desenvolver um algoritmo que leia um número não determinado de valores e calcule e escreva a média aritmética dos valores lidos, 
a quantidade de valores positivos, a quantidade de valores negativos e o percentual de valores negativos e positivos. 
*/

int main() 
{
	int x, read, positivos = 0, negativos = 0, total = 0;
	printf("Quantos valores quer ler? ");
	scanf("%d", &x);
	for(int i = x ; i > 0 ; i--)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &read);
		total += read;
		
		if(read >= 0) positivos++;
		else negativos++;
	}
	printf("Media: %d \nPositivos: %d \nNegativos: %d \nPercentual Positivos: %.0f \nPercentual Negativos: %.0f", total/x, positivos, negativos, ((float)positivos*100)/x, ((float)negativos*100)/x);
}
