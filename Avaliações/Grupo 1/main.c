#include <stdio.h>
#include <stdlib.h>

/*18/03 - Pedro - Alterei os scanf como o prof explicou na aula de sexta,
  assim as letras já nao dão um loop infinito.
  Reparei tambem que as vezes a inicialização do "int opcao" ficava com o valor
  0, então dava problema no switch/if, para resolver meti na inicialização int
  opcao = 10, pois 10 nunca vai ser uma opcao valida
*/

/*19/03 - Zuil - Coloquei um exemplo de scan que possa resolver o problema da
 * leitura do char. Vi que ja chegaram o getchar mas atente para casos onde for
 * um string composto por numeros e letras. Ex: '1a'
 */

// Definição das funções
void disciplinas();
void menuPrincipal();
void conteudoDisciplina();
void conteudoCalendario();

int main(void) {
  menuPrincipal(0);
  return 0;
}

void menuPrincipal() {
  int opcao = 10;

  do {
    printf("1 - Disciplinas\n");
    printf("2 - Calendario\n");
    printf("0 - Sair\n");

    // Zuil P.
    // testem depois aqui os casos onde o operador digite algo como '0a', ou
    // '1b'
    if (scanf(" %d", &opcao) != 1) {
      while (getchar() != '\n')
        ;
    }

    switch (opcao) {
    case 1:
      disciplinas();
      break;
    case 2:
      conteudoCalendario();
      break;
    case 0:
      return;

    default:
      printf("Opcao Invalida\n");
    }

  } while (opcao != 0);
}

void disciplinas() {
  int opcao = 10;

  do {
    printf("1 - Recursos Gerais\n");
    printf("2 - LP1\n");
    printf("3 - AED\n");
    printf("4 - Matematica II\n");
    printf("5 - Algebra Linear\n");
    printf("6 - Arq. Computadores\n");
    printf("7 - Comp Compormentais\n");
    printf("0 - Sair\n");

    if (scanf("%d", &opcao) != 1) {
      while (getchar() != '\n')
        ;
    }

    if (opcao == 0) {
      return;
    } else if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 ||
               opcao == 5 || opcao == 6 || opcao == 7) {
      conteudoDisciplina();
    } else {
      printf("Opcao Invalida\n");
    }

  } while (opcao != 0);
}

void conteudoDisciplina() {
  int opcao = 10;

  do {
    printf("1 - Anuncios\n");
    printf("2 - Aulas Teoricas\n");
    printf("3 - Aulas Praticas\n");
    printf("4 - Notas Exames\n");
    printf("0 - Sair\n");

    if (scanf("%d", &opcao) != 1) {
      while (getchar() != '\n')
        ;
    }

    switch (opcao) {
    case 1:
      printf("Opcao 1 escolhido\n");
      break;
    case 2:
      printf("Opcao 2 escolhido\n");
      break;
    case 3:
      printf("Opcao 3 escolhido\n");
      break;
    case 4:
      menuPrincipal();
      break;
    case 0:
      return;

    default:
      printf("Opcao Invalida\n");
      break;
    }

  } while (opcao != 0);
}

void conteudoCalendario() {
  int opcao = 10;

  do {
    printf("1 - Fevereiro\n");
    printf("2 - Marco\n");
    printf("3 - Abril\n");
    printf("4 - Maio\n");
    printf("5 - Junho\n");
    printf("6 - Julho\n");
    printf("0 - Sair\n");

    if (scanf("%d", &opcao) != 1) {
      while (getchar() != '\n')
        ;
    }

    switch (opcao) {
    case 1:
      printf("7 Inicio Aulas\n");
      break;
    case 2:
      printf("Opcao 2 escolhido\n");
      break;
    case 3:
      printf("1 a 16 Ferias Pascoa\n");
      break;
    case 4:
      printf("Opcao 4 escolhido\n");
      break;
    case 5:
      printf("10-17 Pausa\n");
      printf("17-31 Avaliacoes Finais Freq\n");
      break;
    case 6:
      printf("1-15 Avaliacoes Recurso\n");
      break;
    case 0:
      return;
    case 9:
      return;

    default:
      printf("Opcao Invalida\n");
      break;
    }

  } while (opcao != 0);
}