#include <stdio.h>

int main(void) {

  char base;
  int numero;

  printf("Qual a base do numero que quer inserir? ('d' - decimal, 'o' - octal, 'h' - hexadecimal)\n");

  scanf("%c", &base);

  
  if(base == 'd') {
    printf("Insira o Número:\n");
    scanf("%d", &numero);
    
  } else if(base == 'h') {
    printf("Insira o Número:\n");
    scanf("%x", &numero);
    
  } else if (base == 'o') {
    printf("Insira o número:\n");
    scanf("%o", &numero);
    
  } else {
    printf("Base Invalida\n");
    return 1;
  }

  printf("Conversao para Decimal: %d\n", numero);
  printf("Conversao para Octal: %o\n", numero);
  printf("Conversao para Hexadecimal: %X\n", numero);

  return 0;
}