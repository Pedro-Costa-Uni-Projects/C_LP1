#include <stdio.h>

int main(void) {

  char nome[64];
  int i;

  printf("Insira um nome: ");
  scanf(" %[^\n]", nome);

  for(i = 0; i < 4; i++) {
    printf("Letra %d = %c\n", i, nome[i]);
  }

  return 0;
}