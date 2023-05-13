#include <stdio.h>

int main() {

  int i=3, j=5;
  int *p, *q;
  p = &i; //Aponta para 3
  q = &j; //Aponta para 5

  printf("%d\n", p == &i);
  printf("%d\n", *p - *q);
  printf("%d\n", **&p);

  /*
    a) p == &i; -> 1 aka True
    b) *p - *q  -> -2
    c) **&p -> 3
    d) 3* - *q/(*p)+7 -> ??????
  */
  
  return 0;
}
