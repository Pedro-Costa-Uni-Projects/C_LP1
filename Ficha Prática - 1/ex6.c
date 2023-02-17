#include <stdio.h>
int main() 
{
    float valor= 900.25;
    int tamanho;

    tamanho = sizeof(valor);
    printf("Um float : %f\n",valor);
    printf("Um float : %E\n",valor);
    printf("Um float : %e\n",valor);
    printf("espaco de memoria ocupado: %d bytes\n", tamanho);
    return 0;
}