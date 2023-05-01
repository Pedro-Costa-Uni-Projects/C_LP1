#include <stdio.h>

int main(void) {
  int x = 5;
  float y = 5;

  int *px = &x;
  float *py = &y;

  printf("X: %d | Px: %p\n", *px, px);
  printf("Y: %f | Py: %p\n", *py, py);

  return 0;
}