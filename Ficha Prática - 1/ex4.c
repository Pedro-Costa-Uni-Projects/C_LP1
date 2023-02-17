#include <stdio.h>
int main() 
{
    int notaTeste1 = 15, notaTeste2 = 15, notaTeste3 = 17; 
    double media;

    media = (notaTeste1 + notaTeste2 + notaTeste3)/3.0;
    printf("Nota final : %f valores\n", media);
    printf("Nota final : %3.0f valores\n", media);
    printf("Nota final : %0.2f valores\n", media);
    printf("Nota final : %9.2f valores\n", media);
    //antes do ponto numero de posições para escrever o numero
    //depois do ponto casas numero de casas decimais
    return 0;
}