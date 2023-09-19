/* CABEÇALHO
* Nome: Gabriel Antunes Soares
* Questão 1: Lista Somadora
*
* Simples lista que vai iterando e somando enquanto não chegar no final da lista, ie NULL.
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
  int value;
  struct Node *next;
} node;

bool menu(node **root);
void findAll(node *root);
void insert (node **root, int value);
void append(node **root, int value);

int main() {
  node *root = NULL;
  while(menu(&root)) {}
}

bool menu(node **root) {
  int option, value;
  printf("\n--------------------------------\n");
  printf("\n\nMenu:\n");
  printf("1 - Adicionar valor\n");
  printf("2 - Mostrar lista\n");
  printf("0 - Exit\n");
  printf("\n--------------------------------\n");
  printf("Option: ");
  scanf("%d", &option);

  switch (option) {
    case 1:
      printf("Value: ");
      scanf("%d", &value);
      append(root, value);
      break;
    case 2:
      findAll(*root);
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

void findAll(node *root) {
  node *temp = root;

  printf("Find All Result:\n");
  while (temp != NULL) {
    printf("\nAdress: %p\nValue: %d\nNext: %p", temp, temp->value, temp->next);
    printf("\n-----------------------------");
    temp = temp->next;
    if(temp == root) {return;}
  }
}

void append (node **root, int value) {
  node *temp = *root;
  node *newNode = malloc(sizeof(node));
  newNode->value = value;
  newNode->next = NULL;
  
  if (temp == NULL) {
    insert(root, value);
    return;
  }
  
  while (temp->next != NULL) {
    temp->value += value;
    temp = temp->next;
  }
  
  temp->value += value;
  temp->next = newNode;
}

void insert (node **root, int value) {
  node *temp = malloc(sizeof(node));
  temp->value = value;
  temp->next = *root;
  *root = temp;
}


