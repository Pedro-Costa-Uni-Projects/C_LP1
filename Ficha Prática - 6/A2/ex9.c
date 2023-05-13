#include <stdio.h>

int main() {

  int i=5, *p;
  p = &i;
  printf("%ld %d %d %d %d\n", (long)p,*p+2,**&p,3**p,**&p+4);
  
  return 0;
}

//4094, 7, 5, 15, 9