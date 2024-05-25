#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x;
  int* y; // y is a pointer to an integer x

  char message[30] = "I do not know how this works..";
  // char* point = &message; // Set a pointer to the first character of the message

  // null termination

  // Print out single characters

  printf("%c\n", message[0]);
  printf("%c\n", *message);

  printf("%c\n", message[5]);
  printf("%c\n", *(message + 5)); // Pointer arithmetic

  // String manipulation is the same as simply changing values
  *message = 'd';
  printf("%s\n", message);

  return 0;
}
