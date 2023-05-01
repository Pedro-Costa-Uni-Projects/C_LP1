#include <stdio.h>

int main(int argc, char* argv[]) {

  if (argc == 1) {
    puts("No arguments");
    return 0;
  }

  for(int i = 1; i < argc; i++) {
    printf("%d -> %s\n", i, argv[i]);
  }
  
  
  return 0;
}