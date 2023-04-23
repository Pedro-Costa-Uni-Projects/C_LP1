#include <stdio.h>

int checkOrderOfNumers(int num1, int num2, int num3, int num4);
int overlapedCalc(int num1, int num2, int num3, int num4);
int includedCalc(int num1, int num2, int num3, int num4);

int main(void) {

  // variaveis de calculo
  int included = 0;
  int overlaped = 0;
  int totalCases = 0;

  // quntos numeros o scanf leu
  int totalInputs = 0;

  // array para guardar input
  int input[4];

  do {

    totalInputs =
        scanf(" %d-%d,%d-%d", &input[0], &input[1], &input[2], &input[3]);

    // programa acaba se nao ler 4 numeros
    if (totalInputs != 4) {
      break;
    }

    // programa acaba se num1 < num2, num3 < num4
    if (checkOrderOfNumers(input[0], input[1], input[2], input[3])) {
      break;
    }

    // Calcular overlaped
    overlaped += overlapedCalc(input[0], input[1], input[2], input[3]);

    // Calcular included
    included += includedCalc(input[0], input[1], input[2], input[3]);

    // Calcular total case
    totalCases++;

  } while (1);

  printf("intervals included %d ", included);
  printf("intervals overlaped %d ", overlaped);
  printf("total cases %d\n", totalCases);

  return 0;
}

int checkOrderOfNumers(int num1, int num2, int num3, int num4) {
  if (num1 > num2 || num3 > num4) {
    return 1;
  }

  return 0;
}

int overlapedCalc(int num1, int num2, int num3, int num4) {
  if (num2 >= num3) {
    if (num1 <= num4) {
      return 1;
    }
  }

  return 0;
}

int includedCalc(int num1, int num2, int num3, int num4) {
  // par2 incluido par1
  if (num3 >= num1) {
    if (num4 <= num2) {
      return 1;
    }
  }

  // par1 incluido par2
  if (num1 >= num3) {
    if (num2 <= num4) {
      return 1;
    }
  }

  return 0;
}