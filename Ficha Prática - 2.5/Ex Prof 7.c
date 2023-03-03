#include <stdio.h>

int main(void) {

  int number;

  printf("Insira um numero:\n");

  scanf("%d", &number);

  if (number % 2 == 0) {
    printf("%d é par\n", number);
  } else {
    printf("%d é impar\n", number);
  }

  return 0;
}