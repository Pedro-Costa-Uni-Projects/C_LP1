#include <stdio.h>
#include <string.h>

void strset(char *str, char ch) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = ch;
  }
}

int main() {
  char str[50] = "Ola Teste";
  strset(str, 'a');
  printf("Str: %s\n", str);

  return 0;
}