/*
2) Desenvolver um algoritmo que leia a altura de 15 pessoas. 
Este programa deverá calcular e mostrar: 
 a. A menor altura do grupo; 
b. A maior altura do grupo; 
*/

#include <stdio.h>

int main() 
{
    float n, maior = 0, menor = 100;

    for(int pessoa = 1; pessoa <= 15 ; pessoa++)
    {
        n = 0;
        while(n <= 0)
        {
            printf("Digite a algura da pessoa %d: ", pessoa);
            scanf("%f", &n);
        }

        if(n > maior) maior = n;
        if(n < menor) menor = n;
    }

    printf("A menor pessoa tem: %.2f \nA maior pessoa tem: %.2f", menor, maior);
}
