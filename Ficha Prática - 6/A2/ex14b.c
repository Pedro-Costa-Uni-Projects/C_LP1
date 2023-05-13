#include <stdio.h>

int main() {

  int vet[] = {4,9,13};
  int i;
  for(i=0;i<3;i++){
    printf("%ld ",(long)vet+i);
  }

  return 0;
}

/*
  endereço 4, endereço 9, endereço 13
*/