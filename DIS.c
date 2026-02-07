#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void displayCalculator() {
    printf("\n========================================\n");
    printf("         Simple Calculator\n");
    printf("========================================\n");
}

void displayMenu() {
    printf("\nNumber buttons: 0-9\n");
    printf("Operator buttons: + - * / %%\n");
    printf("Special buttons: = (Calculate), C (Clear), Q (Quit)\n");
    printf("========================================\n");
}

double calculate(double num1, double num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 != 0)
                return num1 / num2;
            else {
                printf("\nError: Cannot divide by zero!\n");
                return 0;
            }
        case '%':
            return (num1 * num2) / 100;
        default:
            return 0;
    }
}