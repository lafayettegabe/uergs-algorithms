/*
Crie um vetor de 16 posições de inteiros (receba os valores pelo teclado para serem armazenados). 
Posteriormente, troque os 8 primeiros valores pelos 8 últimos e vice-e-versa. Escreva ao final o vetor obtido.
*/

void ler(int *p, int c);
void inverter(int *p, int c);
void escrever(int *p, int c);

int main() 
{
    int arr[16] = {};

    ler(&arr, 16);
}

void ler(int *p, int c) 
{
    scanf("%d", *(p + (16 - c)));
    if(c) ler(p, c-1);
}