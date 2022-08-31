#include <stdio.h>
#include <math.h>

void main()
{
	int num1, num2;
	char op;
	printf("Calculadora | Digite a operacao que deseja realizar:\nEx: 2+2 | Operacoes + - * / ^\n\n");
	if(scanf("%d%[+-*/^]%d", &num1, &op, &num2) != 3) op = '0';
	switch(op)
	{
		case '+':
			printf("Soma: %d + %d = %d\n", num1, num2, num1+num2);break;
		case '-':
			printf("Subtracao: %d - %d = %d\n", num1, num2, num1-num2);break;
		case '*':
			printf("Multiplicacao: %d * %d = %d\n", num1, num2, num1*num2);break;
		case '^':
			printf("Potencia: %d ^ %d = %f\n", num1, num2, pow(num1,num2));break;
		case '/':
			if(num2 != 0) {printf("Divisao: %d / %d = %.2f\n", num1, num2, (float)num1/num2);break;}
		default:
			printf("Voce digitou algo errado.");
	}
}
