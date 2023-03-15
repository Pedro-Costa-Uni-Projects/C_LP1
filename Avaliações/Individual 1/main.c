#include <stdio.h>

int main(void) {

  // guardar os numeros
  int integers[4];

  // guardar a opcao ascendente(a) ou descendente(d), e a opcao yes(y) or no(n)
  char type;

  // para ajudar na ordenacao
  int temp;

  // para guardar a multiplicacao
  int mult = 0;

  printf("Enter four integers:\n>");

  scanf("%d %d %d %d", &integers[0], &integers[1], &integers[2], &integers[3]);

  // Ciclo para o user meter a opcao correta
  do {
    printf("Select (a) for ascending or (d) for descending:\n>");

    scanf(" %c", &type);

    if (type != 'a' && type != 'd') {
      printf("Error: invalid option");
    }

  } while (type != 'a' && type != 'd');

  // Ordenar o array segundo a opcao
  if (type == 'a') {
    // Ascendente
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (integers[i] > integers[j]) {
          temp = integers[i];
          integers[i] = integers[j];
          integers[j] = temp;
        }
      }
    }

  } else {
    // Descendente
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (integers[i] < integers[j]) {
          temp = integers[i];
          integers[i] = integers[j];
          integers[j] = temp;
        }
      }
    }
  }

  // Imprimir para o ecra o array ordernado
  printf("Sorted array:\n");
  for (int i = 0; i < 4; i++) {
    printf("%d ", integers[i]);
  }

  printf("\n");

  // Ciclo para o user meter a opcao correta
  do {
    printf("Continue - (y) yes, (n) no?\n>");

    scanf(" %c", &type);

    if (type != 'y' && type != 'n') {
      printf("Error: invalid option");
    }

  } while (type != 'y' && type != 'n');

  if (type == 'n') {
    printf("Bye\n");
    return 0;

  } else if (type == 'y') {
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (integers[i] + integers[j] == 2023) {
          mult = integers[i] * integers[j];
          break;
        }
      }

      if (mult != 0) {
        break;
      }
      
    }

    if (mult != 0) {
      printf("The multiplication of the pair that sums up to 2023 is: %d\n", mult);
      return 0;

    } else {
      printf("No pair of integers add up to 2023.\n");
      return 0;
      
    }

  } else {
    return 1;
    
  }
  return 0;
  
}