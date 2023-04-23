#include <stdio.h>

int main(void) {

  int values[8];
  int i;
  int sumBig30 = 0;
  int sum = 0;

  for (i = 0; i < 8; i++) {
    printf("Insira um numero (%d): ", i);
    scanf(" %d", &values[i]);
  }

  for (i = 0; i < 8; i++) {
    if (values[i] > 30) {
      sumBig30 += values[i];
    }
    sum += values[i];
    printf("values[%d] = %d\n", i, values[i]);
  }

  printf("Sum Bigger then 30: %d\n", sumBig30);
  printf("Sum total: %d\n", sum);

  return 0;
}