#include <stdio.h>

int main() {
  int numero = 10;
  int *pNum = &numero;

  printf("Numero -> %d\n", *pNum);

  *pNum = 15;

  printf("Numero -> %d\n", *pNum);

  return 0;
}