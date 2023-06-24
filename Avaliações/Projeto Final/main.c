/**
 * Author: Pedro Costa
 * Created: 03/06/2023
 * Final Delivery Day: 18/06/2023 - 23:59
 * Projeto Final Linguagens de Programação I - 2022/2023
 * Port Manager
 **/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINES
#define MENU                                                                   \
  "+---- MENU\n"                                                               \
  "| move          [-g grua] [-d ponto] [-p pilha] [-D ponto] [-P pilha] [-n " \
  "numero_de_contentores]\n"                                                   \
  "| show          [-d ponto] [-e embarc]\n"                                   \
  "| where         [embarc]\n"                                                 \
  "| navigate      [-e embarc] [-d ponto]\n"                                   \
  "| load          [-e embarc] [-p pilha] [-c contentor:peso]\n"               \
  "| weight        [embarc]\n"                                                 \
  "| save          [filename]\n"                                               \
  "| help\n"                                                                   \
  "| quit\n"                                                                   \
  "+----"

#define ERR_INVALID_COMMAND "ERROR: invalid command"
#define ERR_OPEN_FILE "ERROR: could not open file"
#define ERR_FILE_FORMAT "ERROR: file format is not recognized"
#define SUC_OPERATION_CONCLUDED "SUCCESS: operation concluded"

// STRUCTS
typedef struct Contentor {
  char codigo[4];
  int peso;
} Contentor;

typedef struct No {
  Contentor contentor;
  struct No *proximo;
} No;

typedef struct PilhaCont {
  No *topo;
} PilhaCont;

typedef struct Embarcacao {
  char matricula[5];
  PilhaCont pilhas[6];
} Embarcacao;

// DECLARAÇÕES FUNÇÕES
void inicializacaoEstaleiro(Embarcacao estaleiro[11]);
void limparComandos(char *comandos[100], int count);
int separarInput(char *comandos[100], char input[100]);
void lerFicheiro(int argc, char *argv[], Embarcacao estaleiro[11]);
void calcularPeso(char matricula[20], Embarcacao estaleiro[11]);
void localizarEmbar(char matricula[20], Embarcacao estaleiro[11]);
void mostrarEmbar(char tipo[3], char *valor, Embarcacao estaleiro[11]);
void guardar(char nomeFicheiro[25], Embarcacao estaleiro[11]);
void navegarEmbar(char tipo[2], char matricula[5], char tipo2[2], char local[5],
                  Embarcacao estaleiro[11]);
void carregar(char tipo[2], char matricula[10], char tipo2[2], char pilha[10],
              char tipo3[2], char contentor[10], Embarcacao estaleiro[11]);

// DECLARAÇÕES FUNÇÕES PILHA
PilhaCont *criarPilha();
int pilhaVazia(PilhaCont *pilha);
void empilhar(PilhaCont *pilha, Contentor contentor);
Contentor desempilhar(PilhaCont *pilha);
Contentor topo(PilhaCont *pilha);
int tamanho_pilha(PilhaCont *pilha);

int main(int argc, char *argv[]) {
  char input[100];

  char *comandos[100];
  int numeroComandos;

  Embarcacao estaleiro[11];

  // Meter matricula a "" & topo pilha a NULL
  inicializacaoEstaleiro(estaleiro);

  // Ler ficheiro
  lerFicheiro(argc, argv, estaleiro);

  puts(MENU);
  while (1) {
    printf(">");
    fgets(input, sizeof(input), stdin);

    // Separar o input para um array de strings
    numeroComandos = separarInput(comandos, input);

    // REMOVER LINHAS
    // for (int i = 0; i < numeroComandos; i++) {
    //   printf("%d -> %s\n", i, comandos[i]);
    // }

    if (!strcmp(comandos[0], "move")) {
      printf("MOVE\n");
    } else if (!strcmp(comandos[0], "show")) { // Feito
      if (numeroComandos == 1) {
        mostrarEmbar("-a", "\0", estaleiro);
      } else if (numeroComandos == 3) {
        mostrarEmbar(comandos[1], comandos[2], estaleiro);
      } else {
        puts(ERR_INVALID_COMMAND);
      }

    } else if (!strcmp(comandos[0], "where")) { // Feito
      localizarEmbar(comandos[1], estaleiro);
    } else if (!strcmp(comandos[0], "navigate")) { // Feito
      if (numeroComandos == 5) {
        navegarEmbar(comandos[1], comandos[2], comandos[3], comandos[4],
                     estaleiro);
      } else {
        puts(ERR_INVALID_COMMAND);
      }

    } else if (!strcmp(comandos[0], "load")) { // Feito
      if (numeroComandos == 7) {
        carregar(comandos[1], comandos[2], comandos[3], comandos[4],
                 comandos[5], comandos[6], estaleiro);
      } else {
        puts(ERR_INVALID_COMMAND);
      }

    } else if (!strcmp(comandos[0], "weight")) { // Feito
      if (numeroComandos == 2) {
        calcularPeso(comandos[1], estaleiro);
      } else {
        puts(ERR_INVALID_COMMAND);
      }

    } else if (!strcmp(comandos[0], "save")) { // Feito
      if (numeroComandos == 2) {
        guardar(comandos[1], estaleiro);
      } else {
        puts(ERR_INVALID_COMMAND);
      }

    } else if (!strcmp(comandos[0], "help")) { // Feito
      puts(MENU);
    } else if (!strcmp(comandos[0], "quit")) { // Feito
      exit(0);
    } else {
      puts(ERR_INVALID_COMMAND);
    }

    // Posivel memory leak?
    limparComandos(comandos, numeroComandos);
  }
}

// FUNÇÕES
void inicializacaoEstaleiro(Embarcacao estaleiro[11]) {
  for (int i = 0; i < 11; i++) {
    strcpy(estaleiro[i].matricula, "");
    for (int j = 0; j < 6; j++) {
      estaleiro[i].pilhas[j].topo = NULL;
    }
  }
}

int separarInput(char *comandos[100], char input[100]) {
  int count = 0, ultimoTokenPosicao, posicaoEnter;
  char *token;

  token = strtok(input, " ");
  while (token != NULL && count < 100) {
    comandos[count] = (char *)malloc(strlen(token) + 1);
    strcpy(comandos[count], token);
    count++;
    token = strtok(NULL, " ");
  }

  // o ultimo token estava a ficar com o \n
  ultimoTokenPosicao = count - 1;
  posicaoEnter = strcspn(comandos[ultimoTokenPosicao], "\n");
  comandos[ultimoTokenPosicao][posicaoEnter] = '\0';

  return count;
}

void limparComandos(char *comandos[100], int count) {
  for (int i = 0; i < count; i++) {
    strcpy(comandos[i], "");
  }
}

// Boa sorte se alguem alguma vez tiver que interpretar esta função. JAVA >>> C
void lerFicheiro(int argc, char *argv[], Embarcacao estaleiro[11]) {
  FILE *ptr;
  char linha[100];
  char *tokens[250];
  int count = 0;

  // Não há ficheiro para ler
  // DESCOMENTAR LINHAS
  if (argc == 1) {
    return;
  }
  ptr = fopen(argv[1], "r");

  // REMOVER LINHA
  // ptr = fopen("input3.txt", "r");

  if (NULL == ptr) {
    puts(ERR_OPEN_FILE);
    exit(0);
  }

  while (fgets(linha, sizeof(linha), ptr) != NULL) {
    char *token;

    if (linha[0] == '\n')
      continue;

    // Remover \t do inicio de cada linha bem com o \n do final
    linha[strcspn(linha, "\t")] = ' ';
    linha[strcspn(linha, "\n")] = '\0';

    token = strtok(linha, " ");

    while (token != NULL) {

      // Processamento
      // printf("%s\n", token);
      if (strcmp(token, "") != 0) {
        tokens[count] = malloc(strlen(token) + 1);
        strcpy(tokens[count], token);
        count++;
      }

      token = strtok(NULL, " ");
    }

    // Meter "" no final para a comparação com 'p' não dar problema
    tokens[count] = malloc(2);
    strcpy(tokens[count], "");

    strcpy(linha, "");
  }

  // Guardar
  for (int i = 0; i < count;) {
    if (*tokens[i] == 'd') {
      int numeroEmbarcacao = tokens[i][1] - '0';

      // Matricula
      i++;
      strcpy(estaleiro[numeroEmbarcacao].matricula, tokens[i]);

      i++;
      if (*tokens[i] == 'p') {
        // Ver Pilhas
        do {
          PilhaCont *pilha = criarPilha();
          int numeroContentores;
          int numeroPilha = tokens[i][1] - '0';

          // Ver numero de Contentores
          i++;
          numeroContentores = (int)(*tokens[i] - '0');
          if (numeroContentores == 0) {
            i++;
            continue;
          }

          for (int j = 0; j < numeroContentores; j++) {
            Contentor novoContentor;
            char linhaToken[10];
            char *token;

            i++;
            strcpy(linhaToken, tokens[i]);
            token = strtok(linhaToken, ":");
            strcpy(novoContentor.codigo, token);

            token = strtok(NULL, " ");
            if (atoi(token) < 500) {
              puts(ERR_FILE_FORMAT);
              exit(0);
            }
            novoContentor.peso = atoi(token);
            empilhar(pilha, novoContentor);
          }
          estaleiro[numeroEmbarcacao].pilhas[numeroPilha] = *pilha;
          i++;

          // REMOVER LINHA
          printf("-> %c\n", *tokens[i]);

        } while (*tokens[i] == 'p');

      } else {
        i--;
      }
    } else {
      i++;
    }
  }

  fclose(ptr);
}

void calcularPeso(char matricula[20], Embarcacao estaleiro[11]) {
  int encontrou = 0;
  int pesoTotal = 0;

  // Ciclo embarcações
  for (int i = 0; i < 11; i++) {
    Embarcacao embarcacao = estaleiro[i];

    if (!strcmp(embarcacao.matricula, matricula)) {
      encontrou = 1;

      // Ciclo Pilhas
      for (int j = 0; j < 6; j++) {
        PilhaCont *pilha = &(embarcacao.pilhas[j]);
        No *atual = pilha->topo;
        while (atual != NULL) {
          pesoTotal += atual->contentor.peso;
          atual = atual->proximo;
        }
      }

      break;
    }
  }

  if (encontrou) {
    printf("%s %d\n", matricula, pesoTotal);
  } else {
    puts(ERR_INVALID_COMMAND);
  }
}

void localizarEmbar(char matricula[20], Embarcacao estaleiro[11]) {
  int local = -1;

  if (strcmp(matricula, "")) {
    // Ciclo embarcações
    for (int i = 0; i < 11; i++) {
      Embarcacao embarcacao = estaleiro[i];
      if (!strcmp(embarcacao.matricula, matricula)) {
        local = i;
        break;
      }
    }

    if (local != -1) {
      printf("%d %s\n", local, matricula);
      return;
    }
  }
  puts(ERR_INVALID_COMMAND);
}

void mostrarEmbar(char tipo[3], char *valor, Embarcacao estaleiro[11]) {
  int count;
  int index;
  Contentor *reverseContentors;

  if (!strcmp(tipo, "-d")) {
    int posicao = atoi(valor);
    if (strcmp(estaleiro[posicao].matricula, "") && strlen(valor) == 1) {
      printf("d%d %s\n", posicao, estaleiro[posicao].matricula);

      for (int j = 0; j < 6; j++) {
        PilhaCont *pilha = &(estaleiro[posicao].pilhas[j]);
        No *atual = pilha->topo;
        if (atual != NULL) {
          printf("\tp%d %d", j, tamanho_pilha(pilha));

          // Isto tudo só para o contentores serem imprimidos como esta no
          // ficheiro, aka ao contrario do que esta na pilha
          count = tamanho_pilha(pilha);

          reverseContentors = (Contentor *)malloc(count * sizeof(Contentor));

          if (reverseContentors == NULL) {
            exit(1);
          }

          index = 0;

          while (atual != NULL) {
            reverseContentors[index++] = atual->contentor;
            atual = atual->proximo;
          }

          for (int k = count - 1; k >= 0; k--) {
            printf(" %s:%d", reverseContentors[k].codigo,
                   reverseContentors[k].peso);
          }

          free(reverseContentors);
          puts("");
        }
      }
      return;
    }

  } else if (!strcmp(tipo, "-e")) {
    int encontrou = 0;
    int i;
    for (i = 0; i < 11; i++) {
      Embarcacao embarcacao = estaleiro[i];
      if (!strcmp(embarcacao.matricula, valor)) {
        encontrou = 1;
        break;
      }
    }

    if (encontrou) {
      printf("d%d %s\n", i, estaleiro[i].matricula);
      for (int j = 0; j < 6; j++) {
        PilhaCont *pilha = &(estaleiro[i].pilhas[j]);
        No *atual = pilha->topo;
        if (atual != NULL) {
          printf("\tp%d %d", j, tamanho_pilha(pilha));

          // Isto tudo só para o contentores serem imprimidos como esta no
          // ficheiro
          count = tamanho_pilha(pilha);

          reverseContentors = (Contentor *)malloc(count * sizeof(Contentor));

          if (reverseContentors == NULL) {
            exit(1);
          }

          index = 0;

          while (atual != NULL) {
            reverseContentors[index++] = atual->contentor;
            atual = atual->proximo;
          }

          for (int k = count - 1; k >= 0; k--) {
            printf(" %s:%d", reverseContentors[k].codigo,
                   reverseContentors[k].peso);
          }

          free(reverseContentors);
          puts("");
        }
      }
      return;
    }

  } else if (!strcmp(tipo, "-a")) {
    for (int i = 0; i < 11; i++) {
      Embarcacao embarcacao = estaleiro[i];
      if (strcmp(embarcacao.matricula, "")) {
        printf("d%d %s\n", i, estaleiro[i].matricula);
        for (int j = 0; j < 6; j++) {
          PilhaCont *pilha = &(estaleiro[i].pilhas[j]);
          No *atual = pilha->topo;
          if (atual != NULL) {
            printf("\tp%d %d", j, tamanho_pilha(pilha));

            // Isto tudo só para o contentores serem imprimidos como esta no
            // ficheiro
            count = tamanho_pilha(pilha);

            reverseContentors = (Contentor *)malloc(count * sizeof(Contentor));

            // Check if memory allocation was successful
            if (reverseContentors == NULL) {
              exit(1);
            }

            index = 0;

            while (atual != NULL) {
              reverseContentors[index++] = atual->contentor;
              atual = atual->proximo;
            }

            for (int k = count - 1; k >= 0; k--) {
              printf(" %s:%d", reverseContentors[k].codigo,
                     reverseContentors[k].peso);
            }

            free(reverseContentors);
            puts("");
          }
        }
      }
    }
    return;
  }
  puts(ERR_INVALID_COMMAND);
}

void guardar(char nomeFicheiro[25], Embarcacao estaleiro[11]) {
  if (strcmp(nomeFicheiro, "")) {
    FILE *ptr;
    ptr = fopen(nomeFicheiro, "w");

    if (ptr != NULL) {
      int count;
      int index;
      Contentor *reverseContentors;

      for (int i = 0; i < 11; i++) {
        Embarcacao embarcacao = estaleiro[i];
        if (strcmp(embarcacao.matricula, "")) {
          fprintf(ptr, "d%d %s\n", i, estaleiro[i].matricula);
          for (int j = 0; j < 6; j++) {
            PilhaCont *pilha = &(estaleiro[i].pilhas[j]);
            No *atual = pilha->topo;
            if (atual != NULL) {
              fprintf(ptr, "\tp%d %d", j, tamanho_pilha(pilha));

              // Isto tudo só para o contentores serem imprimidos como esta no
              // ficheiro
              count = tamanho_pilha(pilha);

              reverseContentors =
                  (Contentor *)malloc(count * sizeof(Contentor));

              // Check if memory allocation was successful
              if (reverseContentors == NULL) {
                exit(1);
              }

              index = 0;

              while (atual != NULL) {
                reverseContentors[index++] = atual->contentor;
                atual = atual->proximo;
              }

              for (int k = count - 1; k >= 0; k--) {
                fprintf(ptr, " %s:%d", reverseContentors[k].codigo,
                        reverseContentors[k].peso);
              }

              free(reverseContentors);
              fprintf(ptr, "\n");
            }
          }
        }
      }
      fclose(ptr);
      puts(SUC_OPERATION_CONCLUDED);
      return;
    }
  }
  puts(ERR_INVALID_COMMAND);
}

void navegarEmbar(char tipo[2], char matricula[5], char tipo2[2], char local[5],
                  Embarcacao estaleiro[11]) {
  int localizacao = -1;
  int maiuscula = 0;

  if (!strcmp(tipo, "-e") && !strcmp(tipo2, "-d")) {
    //
  } else if (!strcmp(tipo, "-d") && !strcmp(tipo2, "-e")) {
    char temp[5];

    strcpy(temp, matricula);
    strcpy(matricula, local);
    strcpy(local, temp);

  } else {
    puts(ERR_INVALID_COMMAND);
    return;
  }

  // Tamanho = 4
  if (strlen(matricula) != 4) {
    puts(ERR_INVALID_COMMAND);
    return;
  }

  // Todas são maiusculas
  for (int k = 0; k < (int)strlen(matricula); k++) {
    maiuscula = isupper(matricula[k]);
  }

  if (!maiuscula) {
    puts(ERR_INVALID_COMMAND);
    return;
  }

  for (int i = 0; i < 11; i++) {
    Embarcacao embarcacao = estaleiro[i];
    if (!strcmp(embarcacao.matricula, matricula)) {
      localizacao = i;
      break;
    }
  }

  if (localizacao == -1) {
    // Embarcação não encontrada
    if (strlen(local) == 1 && !strcmp(estaleiro[atoi(local)].matricula, "")) {
      strcpy(estaleiro[atoi(local)].matricula, matricula);
      puts(SUC_OPERATION_CONCLUDED);
      return;
    }
  } else {
    if (strlen(local) == 1 && !strcmp(estaleiro[atoi(local)].matricula, "")) {
      // Mover
      strcpy(estaleiro[atoi(local)].matricula,
             estaleiro[localizacao].matricula);
      strcpy(estaleiro[localizacao].matricula, "");

      memcpy(estaleiro[atoi(local)].pilhas, estaleiro[localizacao].pilhas,
             sizeof(estaleiro[localizacao].pilhas));

      for (int j = 0; j < 6; j++) {
        estaleiro[localizacao].pilhas[j].topo = NULL;
      }
      puts(SUC_OPERATION_CONCLUDED);
      return;
    }
  }
  puts(ERR_INVALID_COMMAND);
  return;
}

void carregar(char tipo[2], char matricula[10], char tipo2[2], char pilha[10],
              char tipo3[2], char contentor[10], Embarcacao estaleiro[11]) {

  int localizacao = -1;
  if (!strcmp(tipo, "-e") && !strcmp(tipo2, "-p") && !strcmp(tipo3, "-c")) {
    //
  } else if (!strcmp(tipo, "-p") && !strcmp(tipo2, "-c") &&
             !strcmp(tipo3, "-e")) {

    char temp[10];
    char temp2[10];
    strcpy(temp, pilha);
    strcpy(temp2, contentor);

    strcpy(pilha, matricula);
    strcpy(contentor, temp);
    strcpy(matricula, temp2);
  } else if (!strcmp(tipo, "-c") && !strcmp(tipo2, "-p") &&
             !strcmp(tipo3, "-e")) {
    char temp[10];
    strcpy(temp, matricula);

    strcpy(matricula, contentor);
    strcpy(contentor, temp);
  } else {
    puts(ERR_INVALID_COMMAND);
    return;
  }

  if (!isdigit(*pilha)) {
    puts(ERR_INVALID_COMMAND);
    return;
  }

  if (atoi(pilha) >= 6) {
    puts(ERR_INVALID_COMMAND);
    return;
  }

  for (int i = 0; i < 11; i++) {
    Embarcacao embarcacao = estaleiro[i];
    if (!strcmp(embarcacao.matricula, matricula)) {
      localizacao = i;
      break;
    }
  }
  if (localizacao != -1) {
    char *token;
    Contentor novoContentor;

    token = strtok(contentor, ":");
    if (strlen(token) != 3) {
      puts(ERR_INVALID_COMMAND);
      return;
    }

    for (int i = 0; i < 6; i++) {
      for (No *atual = estaleiro[localizacao].pilhas[i].topo; atual != NULL;
           atual = atual->proximo) {
        if (strcmp(atual->contentor.codigo, contentor) == 0) {
          puts(ERR_INVALID_COMMAND);
          return;
        }
      }
    }
    strcpy(novoContentor.codigo, token);

    token = strtok(NULL, " ");
    if (atoi(token) < 500) {
      puts(ERR_INVALID_COMMAND);
      return;
    }
    novoContentor.peso = atoi(token);

    if (pilhaVazia(&estaleiro[localizacao].pilhas[atoi(pilha)])) {
      PilhaCont *pilhaNova = criarPilha();
      empilhar(pilhaNova, novoContentor);
      estaleiro[localizacao].pilhas[atoi(pilha)] = *pilhaNova;
    } else {
      empilhar(&estaleiro[localizacao].pilhas[atoi(pilha)], novoContentor);
    }
    puts(SUC_OPERATION_CONCLUDED);
    return;
  } else {
    puts(ERR_INVALID_COMMAND);
    return;
  }
}

// FUNÇÕES PILHA
PilhaCont *criarPilha() {
  PilhaCont *pilha = (PilhaCont *)malloc(sizeof(PilhaCont));
  pilha->topo = NULL;
  return pilha;
}

int pilhaVazia(PilhaCont *pilha) { return (pilha->topo == NULL); }

void empilhar(PilhaCont *pilha, Contentor contentor) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->contentor = contentor;
  novoNo->proximo = pilha->topo;
  pilha->topo = novoNo;
  // REMOVER LINHA
  // printf("Contentor %s empilhado.\n", contentor.codigo);
}

Contentor desempilhar(PilhaCont *pilha) {
  // Meter tudo a zero para dizer que não se pode desempilhar, se for o caso
  Contentor contentorDesempilhado = {{0}, 0};
  if (!pilhaVazia(pilha)) {
    No *temp = pilha->topo;
    contentorDesempilhado = temp->contentor;
    pilha->topo = temp->proximo;
    free(temp);
  }
  return contentorDesempilhado;
}

Contentor topo(PilhaCont *pilha) {
  if (pilhaVazia(pilha)) {
    Contentor contentorDesempilhado = {{0}, 0};
    return contentorDesempilhado;
  }
  return pilha->topo->contentor;
}

int tamanho_pilha(PilhaCont *pilha) {
  int tamanho = 0;
  No *atual = pilha->topo;
  while (atual != NULL) {
    tamanho++;
    atual = atual->proximo;
  }
  return tamanho;
}