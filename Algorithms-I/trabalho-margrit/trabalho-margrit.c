#include <stdio.h>
#include <stdlib.h>

typedef struct tecido {
    int tipo, quantidade;
    struct tecido *next;
} node;

int menu(node **head);
void cadastrar(node **head);
void remover(node **head);
void porTipo(node *head);
void semEstoque(node *head);
void totalEstoque(node *head);
void metrosQuadradosPerRolo(node *head);
int listCount(node *head);
node* createNode();

int main() {
    node *head = NULL;

    while(menu(&head)) {}

    return 0;
}

int menu(node **head) {
    int input = 10;
    while(input < 0 || input > 6) {
        printf("\n\n1 - Cadastrar tecido \n2 - Remover tecido \n3 - Quantidade de rolos estocados por tipo de tecido \n4 - Tipos de tecido sem estoque \n5 - Quantidade total de rolos de tecido estocados \n6 - Quantidade em metros quadrados estocados \n0 - Fim\n\n");
        scanf("%d", &input);
    }
    switch (input)
    {
        case 1: cadastrar(head);                   return 1;
        case 2: remover(head);                     return 1;
        case 3: porTipo(*head);                    return 1;
        case 4: semEstoque(*head);                 return 1;
        case 5: totalEstoque(*head);               return 1;
        case 6: metrosQuadradosPerRolo(*head);     return 1;
        case 0:                                    return 0;
    }
}

void cadastrar(node **head) {
    if(listCount(*head) == 8) {
        printf("Ja ha 8 produtos cadastrados. Remova algum para cadastrar um novo.");
        return;
    }

    node *ptr = *head;

    if(*head == NULL) {
        node *new = createNode();
        *head = new;
        ptr = *head;
    } else {
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        node *new = createNode();
        ptr->next = new;
        ptr = new;
    }
    
    int input = 0;
    while(input < 1 || input > 3) {
        printf("\nDigite o tipo do tecido (1-3): ");
        scanf("%d", &input);
    }
    ptr->tipo = input;

    input = 0;
    while(input <= 0) {
        printf("\nDigite a quantidade de tecido: ");
        scanf("%d", &input);
    }
    ptr->quantidade = input;

    printf("\n\nProduto cadastrado com sucesso! \nID: %d \nTipo: %d \nQuantidade: %d\n", listCount(*head), ptr->tipo, ptr->quantidade);
}

void remover(node **head) {
    if(*head == NULL) {
        printf("\nNao ha produtos cadastrados.");
        return;
    }

    int input = 0;
    while(input <= 0 || input > listCount(*head)) {
        printf("\nInforme a ID do produto que deseja remover: ");
        scanf("%d", &input);
    }

    node *previous = *head;
    node *delete = *head;

    if(input == 1) {
        *head = delete->next;
        free(delete);
        delete = NULL;
    } else {
        while(input != 1) {
            previous = delete;
            delete = delete->next;
            input--;
        }
        previous->next = delete->next;
        free(delete);
        delete = NULL;
    }

    printf("\nProduto deletado com sucesso!\n");
}

void porTipo(node *head) {
    if(listCount(head) == 0) {
        printf("Nao ha produtos cadastrados.");
        return;
    }
    node *ptr = NULL;
    ptr = head;
    int count = 0, tipo = 0;
    while(tipo < 1 || tipo > 3) {
        printf("\nDigit o tipo que voce deseja verificar: ");
        scanf("%d", &tipo);
    }

    while(ptr != NULL) {
        if(ptr->tipo == tipo) count += ptr->quantidade;
        ptr = ptr->next;
        
    }
    (count > 0) ? printf("\nHa %d rolos do tipo %d em estoque.", count, tipo) : printf("\nNao ha nenhum rolo do tipo %d em estoque.", tipo);
}

void semEstoque(node *head) {
    int tipos[3] = {0, 0, 0};
    node *ptr = NULL;
    ptr = head;
    while(ptr != NULL) {
        switch (ptr->tipo) {
        case 1: tipos[0]++; break;
        case 2: tipos[1]++; break;
        case 3: tipos[2]++; break;
        }
        ptr = ptr->next;
    }
    if(tipos[0] == 0) printf("\nEstamos sem estoque do tipo %d", 1);
    if(tipos[1] == 0) printf("\nEstamos sem estoque do tipo %d", 2);
    if(tipos[2] == 0) printf("\nEstamos sem estoque do tipo %d", 3);

}

void totalEstoque(node *head) {
    int count = 0;

    node *ptr = NULL;
    ptr = head;

    while(ptr != NULL) {
        count += ptr->quantidade;
        ptr = ptr->next;
    }
    (count > 0) ? printf("\nHa %d rolos em estoque.", count) : ("\nNao ha nenhum rolo em estoque.");
}

void metrosQuadradosPerRolo(node *head) {
    int count = 0;

    node *ptr = NULL;
    ptr = head;

    while(ptr != NULL) {
        switch (ptr->tipo)
        {
        case 1: count += ptr->quantidade * 5;  break;
        case 2: count += ptr->quantidade * 10; break;
        case 3: count += ptr->quantidade * 6;  break;
        }
        ptr = ptr->next;
    }
    (count > 0) ? printf("\nHa %d metros quadrados de tecido em estoque.", count) : ("\nNao ha nenhum tecido em estoque.");

}

int listCount(node *head) {
    int count = 0;
    node *ptr = NULL;
    ptr = head;
    while(ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

node* createNode() {
    node *new = (node *)malloc(sizeof(node));
    new->tipo = 0;
    new->quantidade = 0;
    new->next = NULL;
    return new;
}