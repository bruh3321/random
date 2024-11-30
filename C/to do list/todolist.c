#include <stdio.h>
#include <string.h>

char tasks[100][100];
int task_count = 0;

void list()
{
    char input[100]; // Temporary variable to hold user input
    while (1)
    {
        printf("Type in your task (enter 'n' to stop): ");
        scanf(" %[^\n]", input); // Read a whole line of input

        if (strcmp(input, "n") == 0)
        {          // Check if input is 'n'
            break; // Exit the loop
        }

        // Store the task in the tasks array
        strcpy(tasks[task_count], input);
        task_count++; // Increment the task count
    }
}

void list_tasks()
{
    if (task_count == 0)
    {
        printf("No tasks to list.\n");
        return; // Exit if there are no tasks
    }

    printf("Your tasks:\n");
    for (int i = 0; i < task_count; i++)
    {
        printf("%d - %s\n", i + 1, tasks[i]); // Print each task
    }
}

int main()
{
    char response[10]; // Array to hold response
    printf("Hello there, this is the task to-do list thingy.\n");

    while (1) // Loop to keep the program running
    {
        printf("Enter 'add' to add tasks to the list, 'list' to list all the tasks, or 'exit' to quit: ");
        scanf("%s", response); // Read the response as a string

        if (strcmp(response, "add") == 0)
        { // Compare strings using strcmp
            list();
        }
        else if (strcmp(response, "list") == 0)
        { // Compare strings using strcmp
            list_tasks();
        }
        else if (strcmp(response, "exit") == 0)
        { // Check if the user wants to exit
            printf("Exiting the program. Goodbye!\n");
            break; // Exit the loop
        }
        else
        {
            printf("Enter a valid response.\n");
        }
    }

    return 0;
}