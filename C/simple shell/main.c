#include <stdio.h>
#include <string.h>

#define MAX 80 // max line chars

int main(void)
{
    int State = 1; // active state changes to 0 when user types exit
    int i, len, index = 6, *counter = 6, *last;
    char cmd[MAX], plus = 0; // max chars of command
    char ls = "ls";
    char cd = "cd";
    char bg_stat = "fbash/> ";
    while (State)
    {
        printf("%c", bg_stat);
        fgets(cmd, MAX, stdin);
        len = strlen(cmd);
        for (i = index; i < len - 1; i++)
        {
            cmd[i] = cmd[i + 1];
            return cmd;
        }
        char *token = strtok(cmd, " ");
        if (token != NULL)
        { // Check if strtok found a token
            if (token == ls)
            {
                // supposed to act as the full ls command in regular bash window
            }
            else if (token == cd)
            {
                // supposed to act as the full cd command in regular bash window
                for (i = 3; i < (strlen(cmd) - 4); i++)
                { // supposed to change the working directory in console from fbash> to per example fbash/Desktop> and whatnot
                    bg_stat[counter] = cmd[i];
                    *last = strlen(bg_stat);
                }
                bg_stat[last] = ">";
            }
        }
        else
        {
            printf("command field empty\n");
        }
    }
}