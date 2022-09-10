/*
Um criador de galinhas deseja saber qual o rendimento diário em ovos. 
O valor da dúzia de ovos varia diariamente, mas ele sabe que todas as suas galinhas estão produzindo 1 ovo por dia. 
Faça o programa para informar quanto em R$ o criador está lucrando com os ovos produzidos.
*/

#include <stdio.h>

int main() {
    int n;
    float valor;

    printf("Quantidade de ovos produzida: ");
    scanf("%d", &n);
    printf("Valor da duzia hoje: R$");
    scanf("%f", &valor);
    printf("Rendimento diario: R$%.2f", n/12 * valor);
}
