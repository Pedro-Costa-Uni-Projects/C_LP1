#include <stdio.h>

int main(void) {

  printf("5 && 6 = %d\n", 5 && 6);
  //Como qualquer coisa != 0 é verdadeiro, 1 && 1 = 1
  
  printf("5 && 0 = %d\n", 5 && 0);
  //Como 5 vale 1 para usos logicos, 1 && 0 = 0

  printf("5 > 2 = %d\n", 5 > 0);
  //5 é maior que 2 logo, a condição é true = 1

  printf("5 == 6 = %d\n", 5 == 6);
  //5 não é igual a 6, logo a condição é falsa = 0

  printf("!5 = %d\n", !5);
  //Como 5 tem como valor logico de 1(true), o contrario de 1(true) é 0(false)

  printf("!0 = %d\n", !0);
  //Contrario de 0(false) é 1(true)

  printf("5+3-2 || 1 = %d\n", 5+3-2 || 1);
  //5+3-2=6, 6 vale 1 logicamente, logo 6 || 1 = 1

  printf("5-6 || 1 = %d\n", 5-6 || 1);
  //-1 tem valor logico 1, logo -1 || 1 = 1

  printf("5+7 || 0 = %d\n", 5+7 || 0);
  //12 tem valor logico 1, logo 12 || 0 = 1

  printf("0*3 || 5*0 = %d\n", 0*3 || 5*0);
  //0 || 0 = 0

  printf("0 || !0 = %d\n", 0 || !0);
  //0 || 1 = 1
  
}