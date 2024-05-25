#include <stdio.h>

int main() {
  if (1 > 2) {
    // Greater than operator - same as python
    printf("If we are here something incredible has happened\n");
  }
  else {
    printf("Obviously 1 is not greater than 2\n");
  }
  if (1 == 1) {
    // Equality
    printf("Crazy, 1 is equal to 1!\n");
  }
  if (1 || 0) {
    // 1 = TRUE, 0 = FALSE
    printf("This is the OR operator!\n");
  }
  if (!(0 && 1)) {
    // The && is the AND operator, which will mean the inner expression is false
    // The ! is the NOT operator, which means the outside is TRUE, meaning that the code inside is run!
    printf("WOWZAS!\n");
  }

  // Two more interesting ones, although I haven't looked at pointers just yet
  int x;
  int* y; // This sets y as a pointer to x
  y = &x; // Now y holds the memory address of x
  printf("Value of y: %p\n", y); // y is now a pointer and hence uses %p as format
  printf("Is the same as\n");
  printf("Where is x stored? %p\n", &x);

}
