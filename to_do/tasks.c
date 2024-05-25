#include <stdio.h>
#include <string.h>
#include "tasks.h"

/*
Create a task
*/
struct task create_task(char* title, char* description, enum priority priority, unsigned int expected_time) {
  struct task new_task = {0};
  // Put the values given as arguments into the struct.

  // strncpy is used for strings because C doesn't allow you to just equate strings
  strncpy(new_task.title, title, MAX_TITLE_LENGTH);
  strncpy(new_task.description, description, MAX_DESCRIPTION_LENGTH);
  new_task.priority = priority;
  new_task.expected_time = expected_time;

  return new_task;


}

/*
Destroy an existing task
*/
void delete_task(char* title, char* description, enum priority priority, unsigned int expected_time) {
  struct task new_task = {0};
  // Check if any tasks match the description and delete it if needed

}

/*
Get the user's input from command line with error handling. Return value indicates whether this was sucessful
*/
int scan_inputs(char* title, char* description, enum priority* priority, unsigned int* expected_time) {

  char line[MAX_LINE_LENGTH];
  printf("Usage: Title <(Max 256 chars)> <Description (Max 1028 chars)>\n<Priority (1, 2 or 3)> <expected_time (in minutes)>\n");
  if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      printf("Error reading input.\n");
      return 0;
  }
  if (sscanf(line, "%s %s %d %u", title, description, priority, expected_time) < 4) {
    printf("Invalid inputs\n");
    return 0;
  }

  if (*priority <= 1) {
    *priority = LOW;
  }
  if (*priority >= 3) {
    *priority = HIGH;
  }
  if (*priority == 2) {
    *priority = MEDIUM;
  }

  return 1;
}

/*
Show all tasks in order of priority
*/
void show_all_tasks() {
  printf("Showing all tasks\n");
}
