#ifndef TASKS_H
#define TASKS_H

#define MAX_TITLE_LENGTH 256
#define MAX_DESCRIPTION_LENGTH 1028
#define MAX_LINE_LENGTH 1300
#define MAX_TASKS 100

// From https://www.w3schools.com/c/c_enums.php
enum priority {
  LOW,
  MEDIUM,
  HIGH
};

// Stores a task struct, which should be eventually stored within specific task files.
struct task {
  char title[MAX_TITLE_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  enum priority priority;
  unsigned int expected_time;
};

int scan_inputs(char* title, char* description, enum priority* priority, unsigned int* expected_time);
struct task create_task(char* title, char* description, enum priority priority, unsigned int expected_time);
void delete_task(char* title, char* description, enum priority priority, unsigned int expected_time);
struct task edit_task(char* title, char* description, enum priority priority, unsigned int expected_time);
void show_all_tasks();

#endif // TASKS_H
