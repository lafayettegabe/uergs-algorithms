#include <stdio.h>

void showMenu() {};
int getMenu() {};

main() {
    int tecidos[7][7] = {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}, tipo[] = {0, 140, 80, 50}, isOn = 1; // Tipo 0, 1, 2 e 3 são null, 140cm, 80cm e 50cm respectivamente | 0 - null é caso não haja.

    while(isOn) {
        showMenu();
        isOn = getMenu();
    }
};

void showMenu() {
    printf("1 - Cadastrar tecido \n2 - Remover tecido \n3 - Quantidade de rolos estocados por tipo de tecido \n4 - Tipos de tecido sem estoque \n5 - Quantidade total de rolos de tecido estocados \n6 - Quantidade em metros quadrados estocados \n0 - Fim \n");
};
int getMenu() {
    int input = 0;
    scanf("%d", &input);

    switch(input) {
        case 0:                  return 0;
        case 1: cadastrar();     return 1;
        case 2: remover();       return 1;
        case 3: qtdTipo();       return 1;
        case 4: tiposZerados();  return 1;
        case 5: totalEstoque();  return 1;
        case 6: totalMetros();   return 1;
    }
}