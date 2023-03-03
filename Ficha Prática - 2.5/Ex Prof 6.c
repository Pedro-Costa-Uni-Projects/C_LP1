#include <stdio.h>

int main(void) {

  char ch;

  printf("Insira um numero, letra ou simbolo:\n");

  scanf("%c", &ch);

  if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
    printf("%c é uma letra\n", ch);

  } else if (ch >= 48 && ch <= 57) {
    printf("%c é um numero\n", ch);

  } else {
    printf("%c é um simbolo\n", ch);
  }

  return 0;
}