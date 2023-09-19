/* CABEÇALHO
*
* Nome: Gabriel Antunes Soares
* Questão 3: Lista Desempilhadeira
*
* Criar duas pilhas, permitir que o usuário adicione e imprima elas
* Ter a opção de desempliar ambas numa lista, um valor de cada de cada vez.
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
  int value;
  struct Node *next;
} node;

int menu(node **pilha1, node **pilha2, node **lista);

// insert node at the beginning of the list
void insert(node **root, int value);

// delete node at the beginning of the list and return the value
int delete(node **root);

// delete node at the end of the list
void pop(node **root);

// desemplilha as duas pilhas na Lista
void desempiliar(node **pilha1, node **pilha2, node **lista);

// print all list
void print(node *root);

int main() {
  node *pilha1 = NULL;
  node *pilha2 = NULL;
  node *lista  = NULL;

  while(menu(&pilha1, &pilha2, &lista)) {}
}

int menu(node **pilha1, node **pilha2, node **lista) {
  int option, value;
  printf("\n--------------------------------\n");
  printf("\n\nMenu:\n");
  printf("1 - Adicionar valor na pilha 1\n");
  printf("2 - Adicionar valor na pilha 2\n");
  printf("3 - Mostrar pilha 1\n");
  printf("4 - Mostrar pilha 2\n");
  printf("5 - Desempilhar na lista\n");
  printf("0 - Exit\n");
  printf("\n--------------------------------\n");
  printf("Option: ");
  scanf("%d", &option);

  switch (option) {
    case 1:
      printf("Value: ");
      scanf("%d", &value);
      insert(pilha1, value);
      break;
    case 2:
      printf("Value: ");
      scanf("%d", &value);
      insert(pilha2, value);
      break;
    case 3:
      printf("Pilha 1:\n");
      print(*pilha1);
      break;
    case 4:
      printf("Pilha 2:\n");
      print(*pilha2);
      break;
    case 5:
      printf("Lista:\n");
      desempiliar(pilha1, pilha2, lista);
      print(*lista);
      break;
    case 0:
      printf("Bye bye\n");
      return false;
    default:
      printf("Invalid option\n");
      break;
  }

  return true;
}

void insert (node **root, int value) {
  node *temp = malloc(sizeof(node));
  temp->value = value;
  temp->next = *root;
  *root = temp;
}

int delete(node **root) {
  int value = 0;
  if(*root == NULL) {
    printf("List is empty\n");
    return value;
  } else {
    node *temp = *root;
    value = temp->value;
    *root = (*root)->next;
    free(temp);
    printf("First node deleted\n");
    return value;
  }
}

void pop(node **root) {
  if(*root == NULL) {
    printf("List is empty\n");
  } else {
    node *temp = *root;
    node *prev = NULL;
    while(temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }
    if(prev == NULL) {
      *root = NULL;
    } else {
      prev->next = NULL;
    }
    free(temp);
    printf("Last node deleted\n");
  }
}

void print(node *root) {
  node *temp = root;

  printf("Find All Result:\n");
  while (temp != NULL) {
    printf("\nAdress: %p\nValue: %d\nNext: %p", temp, temp->value, temp->next);
    printf("\n-----------------------------");
    temp = temp->next;
    if(temp == root) {return;}
  }
}

void desempiliar(node **pilha1, node **pilha2, node **lista) {
  int value;
  while(*pilha1 != NULL || *pilha2 != NULL) {
    if(*pilha1 != NULL) {
      value = delete(pilha1);
      insert(lista, value);
    }
    if(*pilha2 != NULL) {
      value = delete(pilha2);
      insert(lista, value);
    }
  }
}
