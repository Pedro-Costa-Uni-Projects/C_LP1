#include <stdio.h>
#include <string.h>

int main(void) {

  char text[255];

  int i, j;

  scanf(" %[^\n]", text);

  for (i = 0; i < strlen(text); i++) {
    if (text[i] == ' ') {
      text[i] = text[i + 1];
      for (j = i; j < strlen(text); j++) {
        text[j] = text[j+1];
      }
    }
  }

  puts(text);

  return 0;
}