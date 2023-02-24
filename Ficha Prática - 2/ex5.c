#include <stdio.h>

int main(void) {

  float notas[4];
  float media;

  float temp;

  printf("Insira as 4 notas:\n");
  scanf("%f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3]);

  media = (notas[0] + notas[1] + notas[2] + notas[3]) / 4.0;

  printf("Média do aluno: %.1f\n", media);

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (notas[i] > notas[j]) {
        temp = notas[i];
        notas[i] = notas[j];
        notas[j] = temp;
      }
    }
  }

  printf("Notas por ordem: ");
  for (int i = 0; i < 4; i++) {
    printf("%.1f ", notas[i]);
  }

  return 0;
}