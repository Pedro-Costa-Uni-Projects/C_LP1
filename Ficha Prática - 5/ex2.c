#include <stdio.h>

int main(void) {

  int valuesX[5];
  int valuesY[5];
  int i;
  int num;

  //pares
  for (i = 0; i < 5; i++) {
    printf("Insira um numero par: ");
    scanf(" %d", &num);
    if(num % 2 == 0 && num >= 2 && num <= 20) {
      valuesX[i] = num;
    } else {
      i--;
    }
  }

  //impares
  for (i = 0; i < 5; i++) {
    printf("Insira um numero impar: ");
    scanf(" %d", &num);
    if(num % 2 != 0 && num >= 10 && num <= 19) {
      valuesY[i] = num;
    } else {
      i--;
    }
  }

  //print e calculo
  for (i = 0; i < 5; i++) {
    printf("X[%d] + Y[%d] = %d\n", i, i, valuesX[i] + valuesY[i]);
  }

  
  return 0;
}