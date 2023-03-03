#include <stdio.h>

int main(void) {

  int number;

  printf("Insira um numero de 1 a 9:\n");

  scanf("%d", &number);

  if(number >= 10 || number <= 0) {
    printf("Não é um numero entre 1 e 9\n");
    return 1;
  }

  switch (number) {
    case 1:
      printf("%d -> Um\n", number);
      break;
    case 2:
      printf("%d -> Dois\n", number);
      break;
    case 3:
      printf("%d -> Três\n", number);
      break;
    case 4:
      printf("%d -> Quatro\n", number);
      break;
    case 5:
      printf("%d -> Cinco\n", number);
      break;
    case 6:
      printf("%d -> Seis\n", number);
      break;
    case 7:
      printf("%d -> Sete\n", number);
      break;
    case 8:
      printf("%d -> Oito\n", number);
      break;
    case 9:
      printf("%d -> Nove\n", number);
      break;
  }  
  return 0;
}