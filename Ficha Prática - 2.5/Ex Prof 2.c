#include <stdio.h>

int main(void) {

  char letra;

  printf("Insira uma letra: ");

  scanf("%c", &letra);

  if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' ||
      letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' ||
      letra == 'u' || letra == 'U') {
    printf("%c é uma vogal\n", letra);
  } else {
    printf("%c não é uma vogal\n", letra);
  }
  return 0;
}