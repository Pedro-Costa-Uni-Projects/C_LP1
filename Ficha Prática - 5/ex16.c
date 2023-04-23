#include <stdio.h>

int main(void) {

  char nome[64];
  int i;

  printf("Insira um nome: ");
  scanf(" %[^\n]", nome);

  for (i = 0; i < 64; i++) {
    if (nome[i] != '\0') {
      printf("Letra %d = %c\n", i, nome[i]);

    } else {
      break;
    }
  }

  return 0;
}