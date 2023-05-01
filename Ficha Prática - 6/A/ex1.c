#include <stdio.h>

int main(void) {
  int var1;
  int var2 = 15;
  int *ptr = &var1;
  int *ptr2 = ptr;
  *ptr = var2;

  return 0;

  /*
  Endereço	Conteúdo	Identificador
    ...		
   0xFF8B4		 15         var1
               15	        var2
    ...		
   0xFF900	 0xFF8B4      ptr
   0xFF908	 0xFF8B4      ptr2
    ...		
  */
}