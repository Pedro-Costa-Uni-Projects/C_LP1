#include <stdio.h>

int main() {
  int numeros[] = {10, 20, 30};
  int *pNum = &numeros[0]; //Aponta para 10
  printf("Valor = %d\n", *pNum);
  pNum++;
  printf("Valor = %d\n", *pNum);
  pNum = pNum + 1;
  printf("numero via ponteiro = %d\n", *pNum);
  return 0;
}

//Output -> Valor = 10
//          Valor = 20
//          numero via ponteiro = 30