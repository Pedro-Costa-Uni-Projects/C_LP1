#include <stdio.h>

int main(void) {
  // inicializar a variavel x com o tipo int
  int x;

  // ler do terminal um numero decimal e escrever na variavel x
  printf("Digite o numero x:");
  scanf("%d", &x);

  // calcular o dobro do valor que esta na variavel x e escrever para o terminal
  printf("O valor de x x2 é %d\n", 2 * x);
  return 0;
}