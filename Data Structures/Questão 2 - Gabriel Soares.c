/*
* Aluno: Gabriel Antunes Soares
* Questão: FILA INTELIGENTE
* 
* São 3 filas, que suportam até 10 pessoas cada, após isso informar que está cheio
* Um novo cliente entrará na fila mais próxima, a menos que ela seja maior que a próxima+3 
* manter isso de sempre ter uma diferença de no máximo 3 entre as filas
*
*
* Opções de andar a fila incluem: 
*  - Andar fila X (irá remover dinamicamente da fila X 1 de cada vez).
*
* Se em algum momento que X fila andar ela ficar muito menor, será removido clientes das maiores e adicionado eles a ela
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Clientes {
  int senha; // senha é o valor do nó que só server pra substituir o nome do cliente
  struct Node *next;
} cliente;

typedef struct Fila {
  int qtd;
  cliente *inicio;
} fila;

// Funções de menu
bool menu(fila *f1, fila *f2, fila *f3);

// Funções de fila 
fila *criarFila();
void inserir(fila *f, int senha);
void remover(fila *f);
void mostrar(fila *f);
void andar(fila *f);
void loadbalancer(fila *f1, fila *f2, fila *f3);

int main() {
  fila *f1 = criarFila();
  fila *f2 = criarFila();
  fila *f3 = criarFila();

  while(menu(f1, f2, f3)) {}
}

bool menu(fila *f1, fila *f2, fila *f3) {
  static int senha = 1;
  int option;
  printf("\n--------------------------------\n");
  printf("\n\nMenu:\n");
  printf("1 - Adicionar cliente\n");
  printf("2 - Mostrar filas\n");
  printf("3 - Andar fila\n");
  printf("0 - Exit\n");
  printf("\n--------------------------------\n");
  printf("Option: ");
  scanf("%d", &option);

  switch (option) {
    case 1:
      inserir(f1, senha++);
      break;
    case 2:
      printf("Fila: ");
      scanf("%d", &option);
      switch (option) {
        case 1:
          mostrar(f1);
          break;
        case 2:
          mostrar(f2);
          break;
        case 3:
          mostrar(f3);
          break;
        default:
          printf("Opção inválida\n");
          break;
      }
      break;
    case 3:
      printf("Fila: ");
      scanf("%d", &option);
      switch (option) {
        case 1:
          andar(f1);
          break;
        case 2:
          andar(f2);
          break;
        case 3:
          andar(f3);
          break;
        default:
          printf("Opção inválida\n");
          break;
      }
      break;
    case 0:
      printf("Até mais...\n");
      return false;
    default:
      printf("Opção inválida\n");
      break;
  }
  loadbalancer(f1, f2, f3);
  return true;
}

fila *criarFila() {
  fila *f = (fila*) malloc(sizeof(fila));
  f->qtd = 0;
  f->inicio = NULL;
  return f;
}

void inserir(fila *f, int senha) {
  if (f->qtd == 10) {
    printf("Fila cheia\n");
  } else {
    cliente *novo = (cliente*) malloc(sizeof(cliente));
    novo->senha = senha;
    novo->next = NULL;
    if (f->inicio == NULL) {
      f->inicio = novo;
    } else {
      cliente *temp = f->inicio;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = novo;
    }
    f->qtd++;
  }
}

void remover(fila *f) {
  if (f->inicio == NULL) {
    printf("Fila vazia\n");
  } else {
    cliente *temp = f->inicio;
    f->inicio = temp->next;
    free(temp);
    f->qtd--;
  }
}

void mostrar(fila *f) {
  if (f->inicio == NULL) {
    printf("Fila vazia\n");
  } else {
    cliente *temp = f->inicio;
    printf("\nFila:\n");
    while (temp != NULL) {
      printf("Senha: %d | Endereço: %p | Próximo: %p\n", temp->senha, temp, temp->next);
      temp = temp->next;
    }
  }
}

void andar(fila *f) {
  if (f->inicio == NULL) {
    printf("Fila vazia\n");
  } else {
    cliente *temp = f->inicio;
    f->inicio = temp->next;
    free(temp);
    f->qtd--;
  }
}

void loadbalancer(fila *f1, fila *f2, fila *f3) {
  // pra garantir que sempre tenha uma diferença de no máximo 3 entre as filas
  if (f1->qtd > f2->qtd + 3) {
    inserir(f2, f1->inicio->senha);
    remover(f1);
  } else if (f1->qtd > f3->qtd + 3) {
    inserir(f3, f1->inicio->senha);
    remover(f1);
  } else if (f2->qtd > f1->qtd + 3) {
    inserir(f1, f2->inicio->senha);
    remover(f2);
  } else if (f2->qtd > f3->qtd + 3) {
    inserir(f3, f2->inicio->senha);
    remover(f2);
  } else if (f3->qtd > f1->qtd + 3) {
    inserir(f1, f3->inicio->senha);
    remover(f3);
  } else if (f3->qtd > f2->qtd + 3) {
    inserir(f2, f3->inicio->senha);
    remover(f3);
  }
}
