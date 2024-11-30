#include <stdio.h>

int main()
{
    float a, b;
    char op;
    printf("enter 2 real numbers: ");
    scanf("%f %f", &a, &b);
    printf("enter an operator: ");
    scanf(" %c", &op);
    switch (op)
    {
    case '+':
        printf("%f + %f = %f\n", a, b, a + b);
        break;
    case '-':
        printf("%f - %f = %f\n", a, b, a - b);
        break;
    case '*':
        printf("%f * %f = %f\n", a, b, a * b);
        break;
    case '/':
        printf("%f / %f = %f\n", a, b, a / b);
        break;
    default:
        printf("invalid operator\n");
    }
}