#include <stdio.h>

#define MAX 5

int main () 
{    
  int numeros[MAX] = {10, 20, 30, 40, 50};    
  int *pNum = numeros; //Aponta para 10
  while(pNum<=&numeros[MAX-1]) { //&numeros[MAX-1] aponta para 50    
    printf("numero via ponteiro = %d\n", *pNum);      
    pNum++;
  }      
  return 0;  
} 

//Output -> numero via ponteiro = 10
//          numero via ponteiro = 20
//          numero via ponteiro = 30
//          numero via ponteiro = 40
//          numero via ponteiro = 50