#include <stdio.h>

void calcular_dados(int *soma, float *media, int x, int y) {
  *soma = x + y;
  *media = *soma / 2;
}

int main() {
  int x = 10, y = 15;
  int soma;
  float media;
  calcular_dados(&soma, &media, x, y);
  printf("Soma = %d\n", soma);
  printf("Media = %f\n", media);
  return 0;
}