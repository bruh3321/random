#include <string.h>

int hash(char *token)
{
    if (strcmp(token, "ls") == 0)
        return 1;
    if (strcmp(token, "cd") == 0)
        return 2;
    if (strcmp(token, "exit") == 0)
        return 3;
    if (strcmp(token, "pwd") == 0)
        return 4;
    return 0;
}