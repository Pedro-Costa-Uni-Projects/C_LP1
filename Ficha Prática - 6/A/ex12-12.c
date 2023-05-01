#include <stdio.h>
#include <string.h>

void myStrcpy(char *dest, char *orig) {
  for(int i = 0; orig[i] != '\0'; i++) {
    dest[i] = orig[i];
  }
}

void myStrcat(char *dest, char *orig) {
  int lastChar = 0;
  int i, j;
  for(i = 0; dest[i] != '\0'; i++) {
    lastChar = i;
  }

  lastChar++;


  for(j = 0; orig[j] != '\0'; j++) {
    dest[lastChar + j] = orig[j];
  }

  dest[lastChar + j] = '\0';
}

int main() {
  char orig[50] = "Ola Teste";
  char dest[50] = "123 ";

  myStrcat(dest, orig);
  
  printf("Orig: %s\n", orig);
  printf("Dest: %s\n", dest);

  return 0;
}