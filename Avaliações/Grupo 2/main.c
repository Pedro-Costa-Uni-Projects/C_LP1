/*
Para os grupos com dificuldades, recomendamos a seguinte abordagem:
  •	Revisão do programa e compreensão de como este cumpre o enunciado;
  •	Utilização de um debugger, linha a linha, de forma a identificar onde
ocorrem os erros.

Pistas: os erros adicionais podem ser resolvidos se os alunos verificarem o
seguinte:
  •	Os outputs mostrados no enunciado são exatamente iguais;
  •	As variáveis locais são realmente necessárias, ou devia ser usada outra
variável ou parâmetro;
  •	Verificar se as condições e "switches" cobrem todas as linhas de código,
adicionando chavetas ou outro separador para definir corretamente as linhas que
a condição cobre;
  •	Verificar se todos os parâmetros das funções estão a ser usados, ou se
está a ser utilizado o parâmetro errado da função;
  •	Verificar o uso correto dos operadores, por exemplo, se uma condição
está incorreta;
  •	Verificar se o tamanho dos dados declarados é
apropriado;
  •	Verificar o uso correto de ponto e vírgula como terminador das
instruções;
  •	Verificar se as variáveis estão corretamente inicializadas.
*/

#include <stdio.h>
#include <stdlib.h>

#define MENU "\n 1 - Analise sintatica\n 2 - Sair\n"
#define SAIR 2
#define MSG_FNE "FNE - Ficheiro nao existe!\n"
#define MSG_FBF "\nFBF - Ficheiro bem formado!\n"
#define MSG_FMF "\nFMF - Ficheiro mal formado!\n"

#define MSG_ERRO_TIPO " "
#define MSG_ERR2_UNDERFLOW "\nerro 02: stack underflow!\n"

// Antes #define MSG_ERR1_UNDERFLOW "\nerro 01: stack overflow!\n"
#define MSG_ERR1_OVERFLOW "\nerro 01: stack overflow!\n"

/* Enumerado listandos todos tipos de elements json a serem identificados */
enum Elemento_json_e {
  elemento_json_ERRO = 0,
  elemento_json_STRING,
  elemento_json_NUMBER,
  elemento_json_OBJECT,
  elemento_json_OBJECT_END,
  elemento_json_ARRAY,
  elemento_json_ARRAY_END
};
typedef enum Elemento_json_e Elemento_json;

/* Estrutura que vai conter as pilhas de cada tipo json
   Cada pilha conta push e pops */
typedef struct t_contadorElementos {
  int pilha_STRING;
  int pilha_NUMBER;
  int pilha_OBJECT;
  int pilha_ARRAY;
} contadorElementos;

/**
 * Funcoes auxiliares, identifiam pelo conteudo qual o tipo element json
 */
int json_e_string(char ch) { return ch == '"'; }

int json_e_number(char ch) {
  return (ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '.' ||
         ch == 'e' || ch == 'E';
}

int json_e_object(char ch) { return ch == '{'; }

int json_e_object_end(char ch) { return ch == '}'; }

int json_e_array(char ch) { return ch == '['; }

int json_e_array_end(char ch) { return ch == ']'; }
/**
 * Fim Funcoes auxiliares
 */

/**
 *
 * Funcao pop - Imprime o elemento json associado ao seu enumerado
 *
 **/
void printElement(Elemento_json elem) {
  switch (elem) {
  case elemento_json_STRING:
    printf("\"");
    break;

  case elemento_json_ARRAY:
    printf("[");
    break;
  case elemento_json_ARRAY_END:
    printf("]");
    break;

  case elemento_json_NUMBER:
    printf("NUMBER");
    break;

  case elemento_json_OBJECT:
    printf("{");
    break;
  case elemento_json_OBJECT_END:
    printf("}");
    break;

  /* Caso nao seja um tipo identificado imprime um ponto interrogacao */
  case elemento_json_ERRO:
  default:
    printf("?");
  }
}

/**
 *
 * Funcao pop - Diminui por menos 1 valor da pilha
 *              Imprime qual o tipo que ta a fazer pop
 *              Da erro no caso da pilha for menor que zero (stack underflow)
 *              Devolve valor pilha atualizado
 *              No caso de stack underflwo devolve valor -1 da pilha
 *
 **/
int pop(int pilha, Elemento_json tipo) {

  /* Imprime o tipo */
  printf("\n pop  ");
  printElement(tipo);

  /* Decrementa pilha e depois verifica se deu stack underflow */
  pilha--;
  if (pilha < 0) {
    printf(MSG_ERR2_UNDERFLOW);
    pilha = -1;
  }
  return pilha;
}

/**
 *
 * Funcao push - Aumenta por mais 1 valor da pilha
 *               Imprime qual o tipo que ta a fazer push
 *               Da erro no caso da pilha for maior que max_stack
 *(stack_overflow) Devolve valor pilha atualizado No caso de stack overflow
 *devolve valor -1 da pilha
 *
 **/
int push(int pilha, int max_stack, Elemento_json tipo) {
  /* Imprime o tipo */
  printf("\npush ");
  printElement(tipo);

  /* Incrementa pilha e depois verifica se deu stack overflow */
  pilha++;
  if (pilha > max_stack) {

    // Antes printf(MSG_ERR1_UNDERFLOW);
    printf(MSG_ERR1_OVERFLOW);

    pilha = -1;
  }

  return pilha;
}

/**
 *
 * Deteta qual o tipo de elemento json que representa o caracter ch
 *
 */
Elemento_json ler_Elemento_json(char ch) {
  Elemento_json tipo; /* Variavel que contem o tipo detetado */

  if (json_e_string(ch))
    tipo = elemento_json_STRING;

  else if (json_e_object(ch))
    tipo = elemento_json_OBJECT;

  else if (json_e_object_end(ch))
    tipo = elemento_json_OBJECT_END;

  else if (json_e_array(ch))
    tipo = elemento_json_ARRAY;

  else if (json_e_array_end(ch))
    tipo = elemento_json_ARRAY_END;

  else if (json_e_number(ch))
    tipo = elemento_json_NUMBER;

  else
    tipo = elemento_json_ERRO;

  return tipo;
}

/**
 *
 * Funcao que mostra o conteudo do menu
 * Conteudo feito num #define no inicio do ficheiro
 *
 */
int menu() {
  int opcao = 2; /* Variavel que contem o resultado opcao tomada do menu */
  printf(MENU);
  scanf(" %d", &opcao);
  return opcao;
}

// Antes - contadorElementos parse(char str, contadorElementos x, int
// nomesemsentido) {
contadorElementos parse(char str, contadorElementos x, int stackSize) {
  // Antes - enum Elemento_json_e nomecemsentido = ler_Elemento_json(str);
  enum Elemento_json_e elementoLido = ler_Elemento_json(str);

  // Antes - contadorElementos cont; - dizia que x nao era usado
  contadorElementos cont = x;

  switch (elementoLido) {
  case elemento_json_STRING:
    if (cont.pilha_STRING == 1)
      cont.pilha_STRING = pop(cont.pilha_STRING, elementoLido);
    else
      cont.pilha_STRING = push(cont.pilha_STRING, stackSize, elementoLido);
    break;
  case elemento_json_ARRAY:
    cont.pilha_ARRAY = push(cont.pilha_ARRAY, stackSize, elementoLido);

    // Antes nao tinha break, dava erro a dizer que pedia cair para outros
    break;

  case elemento_json_ARRAY_END:
    cont.pilha_ARRAY = pop(cont.pilha_ARRAY, elementoLido);
    break;
  case elemento_json_NUMBER:
    cont.pilha_NUMBER++;
    break;
  case elemento_json_OBJECT:

    // Antes cont.pilha_OBJECT = push(cont.pilha_OBJECT, nomecemsentido,
    // nomesemsentido);
    cont.pilha_OBJECT = push(cont.pilha_OBJECT, stackSize, elementoLido);

    break;
  case elemento_json_OBJECT_END:
    cont.pilha_OBJECT = pop(cont.pilha_OBJECT, elementoLido);
    break;
  case elemento_json_ERRO:
  default:
    printf(MSG_ERRO_TIPO);
  }

  return cont;
}

void detetaErros(contadorElementos resultado) {
  /*Antes -
    if ((resultado.pilha_ARRAY == 0) && (resultado.pilha_OBJECT == 0) &&
      (resultado.pilha_STRING = 0))
  */
  if ((resultado.pilha_ARRAY == 0) && (resultado.pilha_OBJECT == 0) &&
      (resultado.pilha_STRING == 0))
    printf(MSG_FBF);
  else
    printf(MSG_FMF);
}

/* Deteta stack overflow */
int detetaStackOverflow(contadorElementos resultado) {
  /*Antes -
    if ((resultado.pilha_ARRAY == 0) || (resultado.pilha_OBJECT == 0) ||
      (resultado.pilha_STRING == 0))
  */
  if ((resultado.pilha_ARRAY < 0) || (resultado.pilha_OBJECT < 0) ||
      (resultado.pilha_STRING < 0))
    return 1;
  else
    return 0;
}

void analise_sintatica() {

  int stacksize = 0;

  //Antes -   char filename[5];
  char filename[50];

  // Antes - contadorElementos resultado = {}; - dizia nao podia ser inicalizado
  // assim
  contadorElementos resultado = {0, 0, 0, 0};

  FILE *ptr;
  char ch;
  printf("\nInforme o tamanho da stack: ");
  scanf(" %d", &stacksize);
  printf("\nInforme o nome do ficheiro a analisar:");
  scanf(" %s", filename);
  ptr = fopen(filename, "r");
  if (NULL == ptr) {
    printf(MSG_FNE);
    return;
  }

  // Tinha aqui espaço em branco nao sei se é para fazer algo depois
  //
  //
  //
  //
  //
  //

  do {
    ch = fgetc(ptr);
    resultado = parse(ch, resultado, stacksize);
    if (detetaStackOverflow(resultado)) {
      // Antes if vazio, meti break pois nao tenho acerteza do que meter aqui
      // ainda
      break;
    }

    // Antes - ch = EOF; agora nada

  } while (ch != EOF);
  fclose(ptr);
  detetaErros(resultado);
}

/**
 *
 * Funcao principal do programa
 *
 */
int main(void) {

  int opcao = 1; /* Variavel que contem o resultado opcao tomada do menu */

  /* O programa entra num loop que apresenta o menu */
  while (opcao == 1) {
    opcao = menu();
    switch (opcao) {
    /* Se utilizador escolher opcao 1, faz analise sintatica */
    case 1:
      analise_sintatica();
      break;

    // Antes nao tinha case 2, meti para ir para o return 0
    case 2:
      break;

    default:
      /* Sai do programa se opcao nao for as anteriores */
      return 1;
    }
    /* O programa sai do loop com opcao 2, dado com valor SAIR */
  }
  return 0;
}
