#include <stdio.h>

int main(void) {

  int values[8];
  int i;
  int checkNum;
  int flag;

  for (i = 0; i < 8; i++) {
    printf("Insira um numero: ");
    scanf(" %d", &values[i]);
  }

  while (1) {
    printf("Procure um numero: ");
    scanf(" %d", &checkNum);

    flag = 0;

    for (i = 0; i < 8; i++) {
      if (checkNum == values[i]) {
        flag = 1;
        break;
      }
    }

    if (flag) {
      printf("Numero encontrado -> Posicao: %d\n", i);
    } else {
      printf("Numero nao encontrado\n");
    }
  }

  return 0;
}