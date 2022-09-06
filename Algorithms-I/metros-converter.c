/*
Fazer um programa em C que pergunta um valor em metros e imprime o correspondente em centímetros e milímetros. 
*/

#include <stdio.h>

int main() {
    float metro;
    printf("Digita o metro ai: ");
    scanf("%f", &metro);
    printf("Isso e igual a: %.2f centrimetros e %.2f milimetros.", metro*100, metro*1000);
}
