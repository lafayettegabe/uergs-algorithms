/*
Crie um vetor de 16 posições de inteiros (receba os valores pelo teclado para serem armazenados). 
Posteriormente, troque os 8 primeiros valores pelos 8 últimos e vice-e-versa. Escreva ao final o vetor obtido.
*/

#include <stdio.h>

void read(int *p, int c);
void inverter(int *p, int c);
void write(int *p, int c);

int main()
{
    int arr[16] = {};

    read(&arr, 16);
    inverter(&arr, 16);
    write(arr, 16);
}

void read(int *p, int c)
{
    for(int i = 0; i<c; i++)
        scanf("%d", (p + i));
}

void inverter(int *p, int c)
{
    int holder = p[15-c]; // Guarda o valor mais baixo.
    p[15-c] = p[c]; // Mais baixo recebe o mais alto.
    p[c] = holder; // Mais alto recebe o mais baixo.
    if(c > 8) inverter(p, c-1);
}

void write(int *p, int c)
{
    for(int i = 0; i<c; i++)
        printf("%d ", p[i]);
}