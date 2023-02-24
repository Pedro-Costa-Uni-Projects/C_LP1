#include <stdio.h>

int main(void) {

  //inicialização
  float fahrenheit;
  float celsius;

  //ler variavel fahrenheit
  printf("Digite uma temperatura em fahrenheit: \n");
  scanf("%f", &fahrenheit);

  //calcular celsius
  celsius = 5.0 * (fahrenheit - 32.0)/9.0;

  //mostrar no ecrã
  printf("O valor da temperatura em celsius é: %.2f\n", celsius);
  
  return 0;
}