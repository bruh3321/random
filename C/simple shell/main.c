#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 80 // max line chars

int main(void) {
    int state = 1; // active state changes to 0 when user types exit
    int len;
    char cmd[MAX]; // max chars of command
    char bg_stat[MAX] = "fbash/> "; // prompt message

    while (state) {
        printf("%s", bg_stat); // Print the prompt
        fgets(cmd, MAX, stdin); // Read user input
        len = strlen(cmd);
        
        // Remove the newline character from the input
        if (len > 0 && cmd[len - 1] == '\n') {
            cmd[len - 1] = '\0';
        }

        char *token = strtok(cmd, " "); // Get the first token
        if (token != NULL) { // Check if strtok found a token
            if (strcmp(token, "ls") == 0) { // Use strcmp for string comparison
                char *token_second = strtok(NULL, " "); // Get the second token
                if (token_second != NULL) {
                    char system_command[MAX]; // Buffer for the command
                    snprintf(system_command, sizeof(system_command), "ls %s", token_second);
                    system(system_command); // Execute the command
                } else {
                    system("ls"); // If no argument, just run ls
                }
            } else if (strcmp(token, "cd") == 0) { // Use strcmp for string comparison
                char *token_second = strtok(NULL, " "); // Get the second token
                if (token_second != NULL) {
                    if (chdir(token_second) != 0) { // Change directory and check for errors
                        perror("cd failed"); // Print error message
                    } else {
                        // Update the prompt to reflect the new directory
                        snprintf(bg_stat, sizeof(bg_stat), "fbash/%s/> ", token_second);
                    }
                } else {
                    printf("cd: missing argument\n"); // Handle missing argument
                }
            } else if (strcmp(token, "exit") == 0) {
                state = 0; // Exit the loop
            } else {
                printf("Unknown command: %s\n", token); // Handle unknown commands
            }
        } else {
            printf("Command field empty\n"); // Handle empty command
        }
    }
    return 0; // Return success
}