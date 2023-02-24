#include <stdio.h>

int main(void) {

  int hora;
  int minuto;
  int segundo;

  int segundos;

  printf("Qual a hora?\n");
  scanf("%d", &hora);

  printf("Qual o minuto?\n");
  scanf("%d", &minuto);

  printf("Qual o segundo?\n");
  scanf("%d", &segundo);

  segundos = segundo + minuto * 60 + hora * 3600;

  printf("Total de segundos = %d\n", segundos);

  return 0;
}