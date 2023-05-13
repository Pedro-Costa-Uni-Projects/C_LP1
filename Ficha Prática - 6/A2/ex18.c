#include <stdio.h>
#include <string.h>

int myStrlen(char *s) {
  char *first = s;
  char *last = &s[strlen(s) -1];

  printf("%p\n", first);
    printf("%p\n", last);

  return last - first;
}

int main() { 

  char str[100];
  int dif = 0;

  puts("Insira uma string:");
  scanf("%[^\n]", str);

  dif = myStrlen(str);

  printf("Diferença: %d\n", dif);
  
  return 0;
}

/*
Implemente a função myStrlen. Esta função deverá retornar a diferença entre o
primeiro endereço de memória da string e o último. int myStrlen(char *s)
*/
