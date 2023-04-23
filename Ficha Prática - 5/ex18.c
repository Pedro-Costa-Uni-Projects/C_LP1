#include <stdio.h>
#include <string.h>

int main(void) {

  char nome[64];
  int i;

  printf("Insira um nome: ");
  scanf(" %[^\n]", nome);

  printf("Nome invertido: ");
  for (i = strlen(nome) - 1; i >= 0; i--) {
    printf("%c", nome[i]);
  }

  puts("");

  return 0;
}