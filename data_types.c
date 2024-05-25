#include "stdio.h"
#define MAX_NUM 100


int main(int argc, char const *argv[]) {
  int number = 3;
  long big_num = 392382; // Can store bigger numbers than integers
  float float_num = 3.14;
  double float_num = 3.14; // Like floats, but can store even larger or smaller numbers or have higher precision
  int max_num = MAX_NUM; // Use the definitions for easy access
  char e = 'e'; // For one character
  char string[24] = "Never gonna give you up"; // Strings are arrays of characters

  int numbers[5] = {1, 2, 3, 4, 5}; // We can define our own arrays too, with a basic data type
  // followed by the size of the number of numbers we want to store.
  // We always need to specify the number of elements we want to store


  // When printing to terminal each of these needs a different format operator
  printf("For integers we use %%d: %d\n", number);
  printf("For longs we use %%ld: %ld\n", big_num);
  printf("For floats we use %%lf: %f\n", float_num);
  printf("To print a single character we use %%c: %c\n", e);
  printf("And to print a string we need to use %%s\n%s\n", string);

}
