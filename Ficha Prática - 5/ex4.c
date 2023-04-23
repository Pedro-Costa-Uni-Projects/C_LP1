#include <stdio.h>

int main(void) {

  int values[8];
  int i;
  float media = 0.0;
  int multipleOf5 = 0;
  int biggerThen10 = 0;
  int smallerThen30 = 0;
  int biggest = -300000;

  for (i = 0; i < 8; i++) {
    printf("Insira um numero (%d): ", i);
    scanf(" %d", &values[i]);
  }

  puts("Vetor: ");
  for (i = 0; i < 8; i++) {
    printf("%d\t", values[i]);

    if (values[i] > biggest) {
      biggest = values[i];
    }
    
    media+=values[i];
    
    if (values[i]>10) {
      biggerThen10++;
    }
    
    if (values[i]<30) {
      smallerThen30++;
    }
    
    if (values[i] % 5 == 0) {
      multipleOf5++;
    }
  }

  puts("");

  media /= 8;

  printf("Média: %.2f\n", media);
  printf("Multiplos de 5: %d\n", multipleOf5);
  printf("Maiores que 10: %d\n", biggerThen10);
  printf("Menor que 30: %d\n", smallerThen30);
  printf("Maior: %d\n", biggest);

  return 0;
}