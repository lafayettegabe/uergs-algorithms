#include <stdio.h>

/*
2) Desenvolver um algoritmo que leia a altura de 15 pessoas. Este programa deverá calcular e mostrar: 
 a. A menor altura do grupo; 
b. A maior altura do grupo; 
*/

int main() 
{
	float maior = 0, menor = 10, atual;
	
	for(int i = 0; i < 15; i++)
	{
		printf("\nDigite a altura: ");
		scanf("%f", &atual);
		if(atual < menor) menor = atual;
		if(atual > maior) maior = atual;
	}
	
	printf("\nMaior: %.2f\nMenor: %.2f", maior, menor);
}
