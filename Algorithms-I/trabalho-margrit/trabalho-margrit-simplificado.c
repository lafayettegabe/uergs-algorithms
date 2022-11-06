#include <stdio.h>

void mostrarMenu() {
    printf("\n\n1 - Cadastrar tecido \n2 - Remover tecido \n3 - Quantidade de rolos estocados por tipo de tecido \n4 - Tipos de tecido sem estoque \n5 - Quantidade total de rolos de tecido estocados \n6 - Quantidade em metros quadrados estocados \n0 - Fim\n\n");
}

int main() {

    int tecidos[8][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    entrada, count, qtd = 0, isOn = 1;

    while(isOn) {    

        mostrarMenu();
    
        scanf("%d", &entrada);
        while(entrada < 0 || entrada > 6) {
            mostrarMenu();
            scanf("%d", &entrada);
        }

        switch (entrada) {

            case 1:

                if(qtd == 8) {
                    printf("\nJa ha %d produtos cadastrados.", qtd);
                    break;
                }

                while(tecidos[qtd][0] < 1 || tecidos[qtd][0] > 3) {
                    printf("\nDigite a o tipo do produto que deseja cadastrar (1-3): ");
                    scanf("%d", &tecidos[qtd][0]);
                }

                while(tecidos[qtd][1] < 1) {
                    printf("\nDigite a quantidade de tecidos: ");
                    scanf("%d", &tecidos[qtd][1]);
                }

                printf("\n\nProduto cadastrado com sucesso! \nID: %d \nTipo: %d \nQuantidade: %d\n", ++qtd, tecidos[qtd][0], tecidos[qtd][1]);

                break;

            case 2:

                if(qtd == 0) {
                    printf("\nNao ha produtos cadastrados.");
                    break;
                }

                printf("\nDigite a ID do produto que deseja remover (1-%d): ", qtd);
                scanf("%d", &entrada);
                while(entrada < 1 || entrada > qtd) {
                    printf("\nDigite a ID do produto que deseja remover (1-%d): ", qtd);
                    scanf("%d", &entrada);
                }

                for(int i = entrada-1; i < qtd; i++) {
                    tecidos[i][0] = tecidos[i+1][0];
                    tecidos[i][1] = tecidos[i+1][1];
                }

                printf("\n\nProduto removido com sucesso.");
                qtd--;

                break;

            case 3:
                
                if(qtd == 0) {
                    printf("\nNao ha produtos cadastrados.");
                    break;
                }

                printf("\nDigite o tipo que deseja verificar: ");
                scanf("%d", &entrada);
                while(entrada < 1 || entrada > 3) {
                    printf("\nDigite o tipo que deseja verificar: ");
                    scanf("%d", &entrada);
                }

                count = 0;
                for(int i = 0; i <= qtd; i++) {
                    if(tecidos[i][0] == entrada) count+= tecidos[i][1];
                }

                printf("\nHa %d rolos de tecidos do tipo %d.", count, entrada);

                break;

            case 4:

                if(qtd == 0) {
                    printf("\nNao ha produtos cadastrados.");
                    break;
                }

                int tipos[3] = {0, 0, 0};

                for(int i = 0; i <= qtd; i++) {
                    if(tecidos[i][0] == 1)  tipos[0]++;
                    if(tecidos[i][0] == 2)  tipos[1]++;
                    if(tecidos[i][0] == 3)  tipos[2]++;
                }

                if(tipos[0] == 0) printf("\nEstamos sem estoque do tipo 1");
                if(tipos[1] == 0) printf("\nEstamos sem estoque do tipo 2");
                if(tipos[2] == 0) printf("\nEstamos sem estoque do tipo 3");

                break;

            case 5:

                if(qtd == 0) {
                    printf("\nNao ha produtos cadastrados.");
                    break;
                }

                count = 0;

                for(int i = 0; i <= qtd; i++) {
                    count += tecidos[i][1];
                }

                printf("\nHa em estoque %d rolos de tecido.", count);

                break;

            case 6:

                if(qtd == 0) {
                    printf("\nNao ha produtos cadastrados.");
                    break;
                }

                count = 0;

                for(int i = 0; i <= qtd; i++) {
                    if(tecidos[i][0] == 1)  count+= tecidos[i][1] * 5;
                    if(tecidos[i][0] == 2)  count+= tecidos[i][1] * 10;
                    if(tecidos[i][0] == 3)  count+= tecidos[i][1] * 6;
                }

                printf("\nHa em estoque %d metros quadrados de tecido.", count);

                break;

            case 0:

                isOn = 0;

        }
        entrada = 7;
    }
    return 0;
}
