/*
Fazer um programa em C que pergunte um valor em graus Fahrenheit e imprime o  correspondente em graus Celsius usando a fórmula:
      C=(f-32.0) * (5.0/9.0).
*/

#include <stdio.h>

int main() {
    float f;
    printf("Digita a temp ai em Fahrenheit: ");
    scanf("%f", &f);
    printf("Isso e igual a: %.2f Celcius.", (f-32.0) * (5.0/9.0));
}
