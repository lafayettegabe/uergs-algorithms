/*
Laranjas custam R$ 0,30 cada se forem compradas menos do que uma dúzia, e R$ 0,25 se forem compradas pelo menos doze. 
Escreva um programa que leia o número de laranjas compradas, calcule e escreva o valor total da compra
*/

#include <stdio.h>

int main() {
    int x;
 
    scanf("%d", &x);
    (x < 12) ? printf("R$%.2f", x*0.3) : printf("R$%.2f", x*0.25);
}
