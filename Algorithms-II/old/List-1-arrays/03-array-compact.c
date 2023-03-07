/*
Crie um vetor de 15 posições de inteiros e posteriormente realize a compactação dele, 
isto é, elimine as posições com valor zero avançando uma posição, com os com os valores subseqüentes do vetor. 
Dessa forma todos “zeros” devem ficar para as posições finais do vetor.
*/

#include <stdio.h>

void read(int *p, int c);
void compact(int *p, int n);
void write(int *p, int c);

int main()
{
    int arr[15] = {};

    read(&arr, 15);
    compact(&arr, 15);
    write(&arr, 15);
}

void read(int *p, int c)
{
    for(int i = 0; i<c; i++)
        scanf("%d", (p + i));
}

void compact(int *p, int n)
{
    int c = 0; // Contador de números != 0
    for(int i = 0; i < n; i++) 
        if(p[i] != 0) p[c++] = p[i]; // Incrementa o contador e move os valores válidos para frente.
    for(; c < n; c++) 
        p[c] = 0; // Preenche a diferença entre o contador e a array com zeros.
}

void write(int *p, int c)
{
    for(int i = 0; i<c; i++)
        printf("%d ", p[i]);
}