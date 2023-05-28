#include <stdio.h>
#include <stdlib.h>

#define MENU                                                                   \
  "1 - Analise sintatica\n2 - Mostrar stack de simbolos\n3 - Percorrer "       \
  "a stack\n0 - Sair\n> "

// Pedro C
typedef struct No {
  int elemento;
  struct No *proximo;
} No;

typedef struct Pilha {
  No *topo;
} Pilha;

Pilha *criarPilha() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  return pilha;
}

int pilha_vazia(Pilha *pilha) { return (pilha->topo == NULL); }

void empilhar(Pilha *pilha, int elemento) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->elemento = elemento;
  novoNo->proximo = pilha->topo;
  pilha->topo = novoNo;
  printf("push %c\n", elemento);
}

int desempilhar(Pilha *pilha) {
  if (pilha_vazia(pilha)) {
    return -1;
  } else {
    No *temp = pilha->topo;
    int elementoDesempilhado = temp->elemento;
    pilha->topo = temp->proximo;
    free(temp);
    return elementoDesempilhado;
  }
}

int topo(Pilha *pilha) {
  if (pilha_vazia(pilha)) {
    return -1;
  }
  return pilha->topo->elemento;
}

void exibir_pilha(Pilha *pilha) {
  if (pilha_vazia(pilha)) {
    return;
  } else {
    No *atual = pilha->topo;
    printf("Stack:");
    while (atual != NULL) {
      printf(" %c", atual->elemento);
      atual = atual->proximo;
    }
    puts("");
  }
}

int tamanho_pilha(Pilha *pilha) {
  int tamanho = 0;
  No *atual = pilha->topo;
  while (atual != NULL) {
    tamanho++;
    atual = atual->proximo;
  }
  return tamanho;
}

void saltosPilha(Pilha *pilha, int saltos) {
  No *atual = pilha->topo;
  int posicao = 0;
  while (posicao < saltos) {
    atual = atual->proximo;
    posicao++;
  }
  printf("Salto para: %c\n", atual->elemento);
}

int menu() {
  int opcao = 10;
  printf(MENU);
  scanf(" %d", &opcao);
  return opcao;
}

void analiseSintatica(Pilha *pilha) {
  FILE *ptr;
  char ch;
  char filename[50];
  int bemFormatado = 1;

  printf("Informe o nome do ficheiro a analisar: ");
  scanf(" %s", filename);

  ptr = fopen(filename, "r");

  if (NULL == ptr) {
    printf("FNE - Ficheiro nao existe!\n");
    return;
  }

  do {
    ch = fgetc(ptr);

    if (ch == '{' || ch == '[') {
      // se for { ou [, fazer push
      empilhar(pilha, ch);
      // fun empilhar ja tem o printf
    } else if (ch == '}' || ch == ']') {
      // se for } e no topo tiver um {, retira-se {
      if (ch == '}' && topo(pilha) == '{') {
        printf("pop %c\n", desempilhar(pilha));
      } else if ((ch == ']' && topo(pilha) == '[')) {
        // se for ] e no topo tiver um [, retira-se [
        printf("pop %c\n", desempilhar(pilha));
      } else {
        bemFormatado = 0;
        break;
      }
    }

  } while (ch != EOF);

  if (!pilha_vazia(pilha)) {
    bemFormatado = 0;
  }

  if (bemFormatado) {
    printf("FBF - Ficheiro bem formado!\n");
  } else {
    printf("FMF - Ficheiro mal formado!\n");
  }

  fclose(ptr);
}

void mostrarStackPercorrer(Pilha *pilha, int flag) {
  char filename[50];
  int saltos;
  FILE *ptr;
  char ch;

  printf("Informe o nome do ficheiro a analisar: ");
  scanf(" %s", filename);

  ptr = fopen(filename, "r");

  if (NULL == ptr) {
    printf("FNE - Ficheiro nao existe!\n");
    return;
  }

  do {
    ch = fgetc(ptr);
    // se ch igual a um deste caracteres empliha-se na stack (push)
    if (ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ':') {
      empilhar(pilha, ch);
    }
  } while (ch != EOF);

  // usar a função exibir_pilha para dar print a todos até chegar a NULL
  exibir_pilha(pilha);

  if (flag) {
    printf("Informe o numero de saltos: ");
    scanf(" %d", &saltos);

    if (saltos >= tamanho_pilha(pilha)) {
      printf("Saltos maior que o tamanho da pilha!\n");
    } else {
      saltosPilha(pilha, saltos);
    }
  }

  fclose(ptr);
}

int main(void) {
  int opcao = 10;
  Pilha *pilha;

  while (opcao == 10) {
    opcao = menu();
    switch (opcao) {
    case 1:
      pilha = criarPilha();
      analiseSintatica(pilha);
      opcao = 10;
      break;
    case 2:
      pilha = criarPilha();
      mostrarStackPercorrer(pilha, 0);
      opcao = 10;
      break;
    case 3:
      pilha = criarPilha();
      mostrarStackPercorrer(pilha, 1);
      opcao = 10;
      break;
    case 0:
      exit(0);
      break;
    default:
      opcao = 10;
    }
  }

  return 0;
}
