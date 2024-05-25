#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int password_length = atoi(argv[1]);

  int i = 0;

  srand(time(NULL)); // Seed the randomizer (no clue why we do this but i think there is a reason)

  char password[1025] = {0};

  // Make sure we don't destroy the program by having a very long password length
  while (i < password_length && i < 1024) {
    int low_num = 48;
    int high_num = 122;

    // We need to generate passwords with ASCII codes between 48 and 122 for general
    // password applicable characters, this code does the following

    // From https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
    int result = (rand() % (high_num - low_num)) + low_num;
    char result_char = result; // Convert integer to character representation and add to password

    password[i] = result_char;
    i++;

  }

  password[1024] = '\0'; // null terminate

  printf("%s\n", password);

  return 0;
}
