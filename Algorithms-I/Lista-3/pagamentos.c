#include <stdio.h>

main () 
{
	int modoPagamento = 0, parcelas = 0;
	float valor = 0;
	
	while(valor <= 0)
	{
		printf("Qual o valor gasto? \n");
		scanf("%f", &valor);
	}
	
	while(modoPagamento < 1 || modoPagamento > 3)
	{
		printf("Qual a forma de pagamento? \n1 - A vista | 10 porcento de desconto! \n2 2x Sem Juros! \n3 - Ate 10x com apenas 3% de juros! \n");
		scanf("%d", &modoPagamento);
	}
	
	switch(modoPagamento)
	{
		case 1:
			printf("A valor total sera: R$%.2f", valor * 0.9);
			break;
		case 2:
			printf("A valor total sera: R$%.2f", valor);
			break;
		case 3:
			if(valor >= 100)
				{
				while(parcelas < 3 || parcelas > 10)
				{
					printf("Quantas parcelas?");
					scanf("%d", &parcelas);
				}
				
				for(int i = 1; i <= parcelas; i++)
				{
					valor = valor * 1.03;
					printf("A parcela %d eh: R$%.2f\n", i, valor);
				}
			}
			break;
	}
}
