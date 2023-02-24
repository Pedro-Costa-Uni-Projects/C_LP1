#include <stdio.h>

int main(void) {

  //inicialização
  int a;
  int b;
  int c;

  //ler numeros
  printf("Digite dois numeros inteiros A e B: \n");
  scanf("%d %d", &a, &b);

  //trocar valores
  c = b;
  b = a;
  a = c;

  //mostrar no ecrã
  printf("A -> %d | B -> %d\n", a, b);
  
  return 0;
}