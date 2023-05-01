#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* primeiraVogal (char *str) {
  char vogais[5] = {'a', 'e', 'i', 'o', 'u'};

  for (int i = 0; i < (int)strlen(str); i++) {
    for(int j = 0; j < 5; j++) {
      if(tolower(str[i]) == vogais[i]) {
        return &str[i];
      }
    }
  }

  return NULL;
}

int main() {

  char string[] = "Teste";

  printf("String Address: %p\n", string);

  printf("First Vowel Address: %p\n", primeiraVogal(string));

  printf("Vowel: %c\n", *primeiraVogal(string));

  return 0;
}