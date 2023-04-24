/*
3)    Escreva um programa que receba um número inteiro representando a quantidade total de segundos e, 
usando passagem de parâmetros por referência, converta a quantidade informada de segundos em Horas, Minutos e Segundos. 
Imprima o resultado da conversão no formato HH:MM:SS. 
Utilize o seguinte protótipo de função: void converteHora(int total_segundos, int hora, intmin, int *seg)
*/
#include<stdio.h>

void converteHora(int *hora, int *min, int *seg);

int main() {
	int horas = 0, minutos = 0, segundos; 
	
	printf("Informe o total de segundos: ");
	while(segundos <= 0)
		scanf("%d", &segundos);
		
	converteHora(&horas, &minutos, &segundos);

	printf("\n%d:%d:%d", horas, minutos, segundos);
}

void converteHora(int *hora, int *min, int *seg) {
	while(*seg >= 60) {
		if(*seg > 3600) {
			(*hora)++;          // Aumenta uma hora
			*seg -= 3600;    // Diminui 3600 do total de segundos
		} else {
			(*min)++;			 // Aumenta o minuto
			*seg -= 60;		 // Diminui 60 do total de segundos
		}
	}
}
