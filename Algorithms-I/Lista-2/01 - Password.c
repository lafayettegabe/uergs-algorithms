/*
Escreva um programa que verifique a validade de uma senha fornecida pelo usuário. 
A senha válida é o número 1234. Devem ser impressas as seguintes mensagens: 
ACESSO PERMITIDO caso a senha seja válida. ACESSO NEGADO caso a senha seja inválida.
*/

#include <stdio.h>

int main() {
    int pw;
 
    scanf("%d", &pw);
    (pw == 1234) ? printf("ACESSO PERMITIDO") : printf("ACESSO NEGADO");
}
