#include <stdio.h>

#define MAX 255
#define CLOSETIME 23

typedef struct {
  int people;
  int arrivalTime;
} tableContent;

void printRestaurant(tableContent queue[MAX], int currentHour, int endQ, int startQ, tableContent tables[4]);
void initializeTables(tableContent tables[4]);
int maintenance(int currentHour, tableContent tables[4], int endQ, int startQ, tableContent queue[MAX]);
int checkForTable(tableContent tables[4]);
void sitPeople(tableContent tables[4], int people, int hours, int availableTable);
int queueAdd(tableContent queue[MAX], int endQ, int people);
int queueLeave(tableContent queue[MAX], int endQ, int startQ);

int main(void) {

  tableContent queue[MAX];
  tableContent tables[4];
  int endQ = 0, startQ = 0, currentHour = 14;
  int readPeople = -10, readHours = -10;

  int tableAvailableNumber;

  initializeTables(tables);

  do {

    printRestaurant(queue, currentHour, endQ, startQ, tables);

    do {
      printf("Quantas pessoas chegaram?\n");
      scanf(" %d", &readPeople);
    } while (readPeople < 0);

    do {
      printf("Que horas chegaram?\n");
      scanf(" %d", &readHours);
    } while (readHours < currentHour);

    puts("");

    currentHour = readHours;

    startQ = maintenance(currentHour, tables, endQ, startQ, queue);

    // if people == 0 dont do nothing
    if (readPeople != 0) {
      tableAvailableNumber = checkForTable(tables);
      if (tableAvailableNumber == 10) {
        // no table available
        // add to fila
        endQ = queueAdd(queue, endQ, readPeople);

      } else {
        // table available
        // make reservation
        sitPeople(tables, readPeople, readHours, tableAvailableNumber);
      }
    }

  } while (currentHour < CLOSETIME);

  return 0;
}

int queueAdd(tableContent queue[MAX], int endQ, int people) {
  queue[endQ].people = people;
  endQ++;
  return endQ;
}

int queueLeave(tableContent queue[MAX], int endQ, int startQ) {
  if (endQ == startQ - 1) {
    return 0;
  }

  // retornar o valor
  return queue[startQ - 1].people;
}

void printRestaurant(tableContent queue[MAX], int currentHour, int endQ, int startQ, tableContent tables[4]) {
  int i;

  puts("----------");
  printf("Fila: ");
  if (endQ != 0) {
    for (i = startQ; i < endQ; i++) {
      printf("%d-", queue[i].people);
    }
  }
  puts("");
  printf("Hora Atual: %d\n", currentHour);
  puts("----------\n");
  printf("Mesa 1: %d\n", tables[0].people);
  printf("Mesa 2: %d\n", tables[1].people);
  printf("Mesa 3: %d\n", tables[2].people);
  printf("Mesa 4: %d\n", tables[3].people);
  puts("");
}

void initializeTables(tableContent tables[4]) {
  // if not people and arrivalTime get trash
  for (int i = 0; i < 4; i++) {
    tables[i].people = 0;
    tables[i].arrivalTime = 0;
  }
}

int maintenance(int currentHour, tableContent tables[4], int endQ, int startQ, tableContent queue[MAX]) {
  int tableAvailableNumber;
  int peopleToSit;
  int checkTime;
  int i;

  // clean tables max 2 hours
  for (i = 0; i < 4; i++) {
    if (tables[i].arrivalTime != 0) {
      checkTime = 0;
      checkTime += tables[i].arrivalTime;
      if (currentHour - checkTime >= 2) {
        tables[i].people = 0;
        tables[i].arrivalTime = 0;
      }
    }
  }

  if (endQ != startQ) {
    // check if there is people in queue if there is sit them

    do {
      tableAvailableNumber = checkForTable(tables);

      if (tableAvailableNumber != 10) {
        startQ++;
        peopleToSit = queueLeave(queue, endQ, startQ);
        if (peopleToSit != 0) {
          sitPeople(tables, peopleToSit, currentHour, tableAvailableNumber);
        }
      }
    } while (tableAvailableNumber != 10 && endQ != startQ);

    
  }

  return startQ;
}

int checkForTable(tableContent tables[4]) {
  int i;
  for (i = 0; i < 4; i++) {
    if (tables[i].arrivalTime == 0) {
      if (tables[i].people == 0) {
        // table available return table number
        return i;
      }
    }
  }

  // if not return 0, 1, 2, 3 means no table avilable
  return 10;
}

void sitPeople(tableContent tables[4], int people, int hours, int availableTable) {
  // sit people at the table
  tables[availableTable].people = people;
  tables[availableTable].arrivalTime = hours;
}