#include "stdio.h"
#include <stdlib.h> // TO include atoi, convert from string to integer
#include "string.h"

#define MAX_LENGTH 1024

// Decrypt the message by a certain amount
void decrypt(char* message_to_decrypt, int decryption_amount) {
  int i = 0;

  // Common way to loop through a string is to keep going until you encounter a null terminator
  while (message_to_decrypt[i] != '\0' && i < MAX_LENGTH) {
    // Only decrypt alphabetical characters
    char current_char = message_to_decrypt[i];
    if (current_char > 'a' && current_char < 'z') {
      message_to_decrypt[i] = current_char - (decryption_amount % 26);
    }
    else if (current_char > 'A' && current_char < 'Z') {
      message_to_decrypt[i] = current_char - (decryption_amount % 26);
    }
    i++;

  }

}


int main(int argc, char const *argv[]) {

  if (argc < 4) {
    printf("Usage: <message> <message length> <rotated_by>\n");
    return 1;
  }

  unsigned int mes_length = atoi(argv[2]);
  unsigned int rotated_by = atoi(argv[3]);

  char returned_message[MAX_LENGTH + 1] = {0}; // ChatGPT said I should do this

  for (int i = 0; i < mes_length; i++) { // Sizeof will return the number of characters in the message
    char current_char = argv[1][i];
    // Make sure to only rotate letters
    if (current_char > 'A' && current_char < 'Z') {
      current_char = current_char + (rotated_by % 26);
    }
    else if (current_char > 'a' && current_char < 'z') {
      current_char = current_char + (rotated_by % 26);
    }

    returned_message[i] = current_char;

  }


  printf("Encrypted message: %s\n", returned_message);

  char decrypted_message[MAX_LENGTH + 1] = {0};
  decrypt(returned_message, rotated_by);
  strncpy(decrypted_message, returned_message, MAX_LENGTH + 1);
  decrypted_message[MAX_LENGTH] = '\0';
  printf("Decryped message: %s\n", decrypted_message);
  return 0;
}
