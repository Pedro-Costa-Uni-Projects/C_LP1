#include <stdio.h>

int main(void) {

  char ch;

  printf("Insira uma letra:\n");

  scanf("%c", &ch);

  if (ch >= 65 && ch <= 90) {
    printf("%c é uma letra maiscula\n", ch);

  } else if (ch >= 97 && ch <= 122) {
    printf("%c é uma letra minuscula\n", ch);

  } else {
    printf("%c não é uma letra maiscula ou minuscula\n", ch);
  }

  return 0;
}