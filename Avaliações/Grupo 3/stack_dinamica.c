#include <stdio.h>
#include <stdlib.h>

// Estrutura para cada elemento da pilha
typedef struct No {
  int dado;
  struct No *proximo;
} No;

// Estrutura para a pilha
typedef struct Pilha {
  No *topo;
} Pilha;

Pilha *criar_pilha() {
  /*
   * Cria uma nova pilha
   */
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  return pilha;
}

int pilha_vazia(Pilha *pilha) {
  /*
   * Verifica se a pilha está vazia
   */
  return (pilha->topo == NULL);
}

void empilhar(Pilha *pilha, int dado) {
  /*
   * Empilha um elemento
   */
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->dado = dado;
  novoNo->proximo = pilha->topo;
  pilha->topo = novoNo;
  printf("Elemento %d empilhado.\n", dado);
}

int desempilhar(Pilha *pilha) {
  /*
   * Desempilha um elemento
   */
  if (pilha_vazia(pilha)) {
    printf("A pilha está vazia.\n");
    return -1;
  }
  No *temp = pilha->topo;
  int dadoDesempilhado = temp->dado;
  pilha->topo = temp->proximo;
  free(temp);
  return dadoDesempilhado;
}

int topo(Pilha *pilha) {
  /*
   * Retorna o elemento no topo da pilha
   */

  if (pilha_vazia(pilha)) {
    printf("A pilha está vazia.\n");
    return -1;
  }
  return pilha->topo->dado;
}

void exibir_pilha(Pilha *pilha) {
  /*
   * Exibe todos os elementos da pilha
   */

  if (pilha_vazia(pilha)) {
    printf("A pilha está vazia.\n");
    return;
  }
  No *atual = pilha->topo;
  printf("Elementos da pilha: ");
  while (atual != NULL) {
    printf("%d ", atual->dado);
    atual = atual->proximo;
  }
  printf("\n");
}

int tamanho_pilha(Pilha *pilha) {
  /*
   * Retorna o tamanho da pilha
   */
  int tamanho = 0;
  No *atual = pilha->topo;
  while (atual != NULL) {
    tamanho++;
    atual = atual->proximo;
  }
  return tamanho;
}

int main() {
  Pilha *pilha = criar_pilha();

  empilhar(pilha, 10);
  empilhar(pilha, 20);
  empilhar(pilha, 30);
  empilhar(pilha, 40);
  empilhar(pilha, 50);
  empilhar(pilha, 60);
  empilhar(pilha, 70);
  empilhar(pilha, 80);
  empilhar(pilha, 90);

  exibir_pilha(pilha);

  printf("Elemento no topo: %d\n", topo(pilha));

  printf("Elemento desempilhado: %d\n", desempilhar(pilha));

  printf("Elemento no topo: %d\n", topo(pilha));

  printf("Tamanho da pilha: %d\n", tamanho_pilha(pilha));

  exibir_pilha(pilha);

  free(pilha);

  return 0;
}

int json_is_string(char ch) { return ch == '"'; }

int json_is_number(char ch) {
  return (ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '.' ||
         ch == 'e' || ch == 'E';
}