/*
ENDEREÇO      CONTEUDO      IDENTIFICADOR
 0X100c        0XABBA           X[0]
 0X100e        0XC0DD           X[1]
  ...           ...             ...
 0X2000        0X100e            p1
 0x2008        0X2000            p2

Penso que esta certo

*/

#include <stdio.h>

int main() {

  unsigned short int x[2] = {0xABB9, 0xC0DD};
	unsigned short int *p1 = x;
	unsigned short int **p2 = &p1;
	(*p1)++;
	(*p2)++;
	(*p1)++;
  
  return 0;
}