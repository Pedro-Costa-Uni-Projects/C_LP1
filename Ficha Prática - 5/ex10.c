#include <stdio.h>
#include <string.h>

int main(void) {

  int matrix[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {8, 10, 11, 12},
      {13, 14, 15, 16},
  };

  int i;

  for (i = 0; i < 4; i++) {
    printf("%d\n", matrix[i][i]);
  }

  return 0;
}