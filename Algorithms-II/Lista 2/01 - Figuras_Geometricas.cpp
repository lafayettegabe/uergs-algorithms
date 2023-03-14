/*
Exerc�cio 1:
Fazer um programa para calcular a �rea de um quadrado, um ret�ngulo ou um tri�ngulo ret�ngulo. 
O programa deve perguntar qual a figura geom�trica, e ent�o pedir para o usu�rio digitar os tamanhos dos lados (1 � quadrado, 2 � ret�ngulo, 3 tri�ngulo ret�ngulo). 
Um quadrado s� tem um tamanho de lado, o ret�ngulo tem dois, e o tri�ngulo ret�ngulo tamb�m tem dois lados(mais a hipotenusa, mas neste caso n�o � necess�rio digitar este valor).
Ap�s a digita��o, o programa deve calcular a �rea e apresentar ao usu�rio.
Utilizar uma fun��o para a leitura dos lados (verificando se n�o � digitado um valor negativo para o lado), e uma fun��o para o c�lculo de cada �rea. As f�rmulas s�o
�rea_quadrado = lado * lado
�rea_ret�ngulo = lado1 * lado2
�rea_tri�ngulo = (lado 1 * lado 2)/2
*/

#include <stdio.h>

void read(int *figura); // l�
void quadrado();        // calcula quadrado
void retangulo();		// calcula retangulo
void triangulo();		// calcula triangulo

void main() {
	int figura;
	
	read(&figura);
	
	switch(figura) {
		case 1: 
			quadrado();   
			break;
		case 2: 
			retangulo();  
			break;
		case 3: 
			triangulo();  
			break;
	}
}

void read(int *figura) {     // * para acessar o valor
	printf("Informe a opcao desejada para calcular a area: \n1 - Quadrado\n2 - Retangulo\n3 - Triangulo\n\n");
	scanf("%d", figura);
	while(*figura < 1 || *figura > 3) { // * para acessar o valor
		printf("Opcao invalida.\n");
		printf("Informe a opcao desejada para calcular a area: \n1 - Quadrado\n2 - Retangulo\n3 - Triangulo\n\n");
		scanf("%d", figura); // n�o precisa do & pois j� � o endere�o
	}
}

void quadrado() {
	float lado;
	
	printf("\nDigite o tamanho dos lados: ");
	scanf("%f", &lado);
	printf("\nA area do quadrado eh: %.2f", lado * lado);
}

void retangulo() {
	float lado1, lado2;
	
	printf("\nDigite o tamanho do lado 1: ");
	scanf("%f", &lado1);
	printf("\nDigite o tamanho do lado 2: ");
	scanf("%f", &lado2);
	
	printf("\nA area do retangulo eh: %.2f", lado1 * lado2);
}

void triangulo() {
	float lado1, lado2;
	
	printf("\nDigite o tamanho do lado 1: ");
	scanf("%f", &lado1);
	printf("\nDigite o tamanho do lado 2: ");
	scanf("%f", &lado2);

	printf("\nA area do retangulo eh: %.2f", (lado1 * lado2)/2);
}
