/*
Exercício 1:
Fazer um programa para calcular a área de um quadrado, um retângulo ou um triângulo retângulo. 
O programa deve perguntar qual a figura geométrica, e então pedir para o usuário digitar os tamanhos dos lados (1 – quadrado, 2 – retângulo, 3 triângulo retângulo). 
Um quadrado só tem um tamanho de lado, o retângulo tem dois, e o triângulo retângulo também tem dois lados(mais a hipotenusa, mas neste caso não é necessário digitar este valor).
Após a digitação, o programa deve calcular a área e apresentar ao usuário.
Utilizar uma função para a leitura dos lados (verificando se não é digitado um valor negativo para o lado), e uma função para o cálculo de cada área. As fórmulas são
Área_quadrado = lado * lado
Área_retângulo = lado1 * lado2
Área_triângulo = (lado 1 * lado 2)/2
*/

#include <stdio.h>

void read(int *figura); // lê
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
		scanf("%d", figura); // não precisa do & pois já é o endereço
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
