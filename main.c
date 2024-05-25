#include <stdio.h>


int main() {
  char command[100];

  while(fgets(command, 100, stdin) != NULL) {
    printf("Command %s", command);
  }

}
