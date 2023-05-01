#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  char *ptr;

  scanf("%[^\n]", str);

  printf("%s\n", str);

  ptr = &str[strlen(str) - 1];
  while (ptr >= str) {
    printf("%c", *ptr);
    ptr--;
  }
  puts("");

  return 0;
}