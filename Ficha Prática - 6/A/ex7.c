#include <stdio.h>

#define MIN -99999999;
#define MAX 99999999

void calcMinimoEMaximo(int numeros[], int tamanho, int *min, int *max) {
  *min = MAX;
  *max = MIN;

  for (int i = 0; i < tamanho; i++) {
    if (numeros[i] > *max) {
      *max = numeros[i];
    }
    if (numeros[i] < *min) {
      *min = numeros[i];
    }
  }
}

int main() {
  int array[] = {2, 6, 7, 44, -2, 430, 0};
  int min;
  int max;

  calcMinimoEMaximo(array, 7, &min, &max);

  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  
  return 0;
}