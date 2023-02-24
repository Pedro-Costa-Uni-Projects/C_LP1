#include <stdio.h>

int main(void) {

  float a;
  float b;
  float c;

  printf("Intoduza dois números inteiros:\n");
  scanf("%f %f", &a, &b);

  c = a + b;
  printf("A + B = %4.0f\n", c);
  
  c = a - b;
  printf("A - B = %4.0f\n", c);

  c = b - a;
  printf("B - A = %4.0f\n", c);

  c = b * a;
  printf("B * A = %4.0f\n", c);

  if(a == 0 || b == 0) {
    c = 0;
    printf("B / A = %4.0f\n", c);
    printf("A / B = %4.0f\n", c);
  } else {
    c = b / a;
    printf("B / A = %4.2f\n", c);

    c = a / b;
    printf("A / B = %4.2f\n", c);
  }

  return 0;
}