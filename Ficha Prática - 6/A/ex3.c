#include <stdio.h>

void func(int n, int *a, int *b) {
  n = *a;
  *a = *b;
  *b = n++;
}

int main(void) {
  int x = 10, y = 15, z = 5;
  func(z, &x, &y);
  printf("x = %d, y = %d, z = %d\n", x, y, z);
  return 0;
}

/*
x = 15
y = 10 //pois n++ é feito depois
z = 5

func(5, &10, &15)
n = &10
&10 = &15
&15 = 11

*/