#include <stdio.h>

int main(void) {

  int first, second, third;

  printf("Insira 3 numeros:\n");

  scanf("%d %d %d", &first, &second, &third);

  if (first > second) {
    if(first > third) {
      printf("%d é o maior dos 3 números\n", first);
    } else {
      printf("%d é o maior dos 3 números\n", third);
    }
  } else if (second > third) {
    printf("%d é o maior dos 3 números\n", second);
  } else {
    printf("%d é o maior dos 3 números\n", third);
  }
  
  return 0;
}