#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, flag = 1;
  int sum = 0;

  for (i = 1; i < argc; i++) {
    //check if string is a number
    for (int j = 0; argv[i][j] != '\0'; j++) {
      if (!isdigit(argv[i][j])) {
        flag = 0;
        break;
      }
    }

    
    if(flag == 1) {
      sum += atoi(argv[i]);
    }
    
  }

  printf("Sum -> %d\n", sum);

  return 0;
}