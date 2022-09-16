/*
Crie um vetor de 20 posições de inteiros.  
Após o vetor estar todo preenchido com valores informados pelo teclado, 
solicite ao usuário a informação de um número, o qual será procurado no vetor. 
Se o valor for encontrado informe em que posição ele se encontra (a primeira, caso ele esteja armazenado em mais de uma posição). 
Utilize mensagem adequada para o caso do valor não estar armazenado no vetor.
*/

#include <stdio.h>

void read(int *p, int c);
void find(int *p, int *n, int x);

int main()
{
    int n, arr[20] = {};

    read(&arr, 20);
    find(&arr, &n, 0);
}

void read(int *p, int c)
{
    for(int i = 0; i<c; i++)
        scanf("%d", (p + i));
}

void find(int *p, int *n, int x)
{
    if(!x){
        printf("Qual numero deseja buscar? ");
        scanf("%d", &n);
    } else if(x == 20) printf("O numero nao esta na lista.");

    (n == p[x]) ? printf("%d esta na posicao: %d.", n, x+1) : find(p, n, x+1);
}