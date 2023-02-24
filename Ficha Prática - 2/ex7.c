#include <stdio.h>

int main(void) {

  float segundos;

  float dia;
  float hora;
  float minuto;
  float segundo;

  printf("Insira os segundos:\n");
  scanf("%f", &segundos);

  dia = segundos / 86400.0;

  hora = (dia - (int)dia) * 86400.0 / 3600.0;


  minuto = (hora - (int)hora) * 3600.0 / 60.0;

  segundo = (minuto - (int)minuto) * 60.0;

  printf("Dias: %d | Horas: %d | Minutos: %d | Segundo: %d", (int)dia, (int)hora, (int)minuto, (int)segundo);
  
  return 0;
}