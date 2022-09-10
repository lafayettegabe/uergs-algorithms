/*
Um fazendeiro deseja saber quantos litros de água ele está gastando por dia, 
sabendo-se que cada limoeiro necessita de 2 litros de água por dia e cada goiabeira de 3 litros. 
Solicite as informações sobre as quantidades de árvores de cada tipo que o fazendeiro possui e informe a 
quantidade de litros gastos por dia naquela fazenda.
*/

#include <stdio.h>

int main() {
    int nlim, ngoi;

    printf("Digite o numero de Limoeiros e Goiabeiras.\n");
    scanf("%d %d", &nlim, &ngoi);
    printf("Voce esta gastando: %d litros de agua por dia.", nlim*2 + ngoi*3);
}
