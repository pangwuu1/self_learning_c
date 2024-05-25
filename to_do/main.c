#include "stdio.h"
#include "tasks.h"
#include "string.h"

int main(int argc, char const *argv[]) {

  char command[MAX_TITLE_LENGTH] = {0};
  struct task task_array[MAX_TASKS] = {0};
  int task_counter = 0;
  int command_num = 0;

  // Get user input using fgets()
    while (fgets(command, MAX_TITLE_LENGTH, stdin)) {
        printf("Welcome. What would you like to do today?\n"
               "Create a new task - Enter 1\n"
               "Delete an existing task - Enter 2\n"
               "Edit an existing task - Enter 3\n"
               "Show all tasks - Enter 4\n"
               "Quit - Enter 5\n");

        if (sscanf(command, "%d", &command_num) < 1) {
          // Try to parse the command given as an integer. If this doesn't work then return invalid input!
            printf("Invalid input!\n");
            continue;

        } else {
          // Initialize default values
          char title[MAX_TITLE_LENGTH] = {0};
          char description[MAX_DESCRIPTION_LENGTH] = {0};
          enum priority priority = LOW; // Default
          unsigned int hours = 0; // Default

          if (command_num == 1) {
            if (scan_inputs(title, description, &priority, &hours)) {
              struct task new_task = create_task(title, description, priority, hours);
              int i = 0;
              while (strcmp(task_array[i].title, "")) {
                i++;
              }
              task_array[i] = new_task;
            }
          }
          else if (command_num == 2) {
            if (scan_inputs(title, description, &priority, &hours)) {
              int i = 0;
              while (strcmp(task_array[i].title, "")) {
                i++;
              }
              struct task empty_task = {0};
              task_array[i] = empty_task;
            }
          }
          else if (command_num == 3) {
            if (scan_inputs(title, description, &priority, &hours)) {
              int i = 0;
              while (task_array[i].title != title) {
                i++;
              }
              struct task empty_task = {0};
              task_array[i] = empty_task;

              printf("Enter details for new task: ");
              scan_inputs(title, description, &priority, &hours);
              create_task(title, description, priority, hours);

            }
          }
          else if (command_num == 4) {
            unsigned int task_counter = 1;

            for (int i = 0; i < MAX_TASKS; i++) {
              if (strcmp(task_array[i].title, "")) {
                printf("Task %u\n", task_counter);
                printf("Task title: %s\n", task_array[i].title);
                printf("Task description: %s\n", task_array[i].description);
                printf("Task priority: %u\n", task_array[i].priority);
                printf("Task expected hours: %u\n\n", task_array[i].expected_time);

              }
            }

          }


          else if (command_num == 5) {
              return 1;
          }
          else {
              printf("Invalid input! Please enter a number between 1 and 5\n");
          }

        }
    }

  return 1;
}
