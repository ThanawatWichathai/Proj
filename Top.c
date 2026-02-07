#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT] = "";
    char display[MAX_INPUT] = "";
    double num1 = 0, num2 = 0, result = 0;
    char op = '\0';
    int hasOperator = 0;
    char ch;
    
    displayCalculator();
    displayMenu();
    
    while(1) {
        printf("\n----------------------------------------\n");
        printf("Process: %s\n", strlen(display) > 0 ? display : "0");
        printf("----------------------------------------\n");
        printf("Press button: ");
        scanf(" %c", &ch);
        
        // Check for exit
        if(ch == 'Q' || ch == 'q') {
            printf("\nThank you for using!\n");
            break;
        }
        
        // Clear data
        if(ch == 'C' || ch == 'c') {
            strcpy(input, "");
            strcpy(display, "");
            num1 = 0;
            num2 = 0;
            op = '\0';
            hasOperator = 0;
            result = 0;
            printf("Data cleared\n");
            continue;
        }
        
        // Numbers 0-9
        if(ch >= '0' && ch <= '9') {
            char temp[2] = {ch, '\0'};
            strcat(input, temp);
            strcat(display, temp);
        }
        // Operators
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            if(strlen(input) > 0 && !hasOperator) {
                num1 = atof(input);
                op = ch;
                hasOperator = 1;
                strcpy(input, "");
                
                char temp[2] = {' ', ch};
                strncat(display, temp, 2);
                strcat(display, " ");
            } else {
                printf("Please enter a number first!\n");
            }
        }
        // Equal sign
        else if(ch == '=') {
            if(hasOperator && strlen(input) > 0) {
                num2 = atof(input);
                result = calculate(num1, num2, op);
                
                printf("\n========================================\n");
                printf("Process: %s\n", display);
                printf("Answer: %.2f\n", result);
                printf("========================================\n");
                
                // Reset for next calculation
                sprintf(display, "%.2f", result);
                sprintf(input, "%.2f", result);
                num1 = result;
                hasOperator = 0;
                op = '\0';
            } else {
                printf("Please enter a complete expression!\n");
            }
        }
        // Decimal point
        else if(ch == '.') {
            if(strchr(input, '.') == NULL) {
                strcat(input, ".");
                strcat(display, ".");
            } else {
                printf("Decimal point already exists!\n");
            }
        }
        else {
            printf("Invalid button!\n");
        }
    }
    
    return 0;
}