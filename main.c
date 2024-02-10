#include <stdio.h>

#ifndef bool
typedef enum Boolean
{false = 0, true = 1} 
bool;
#endif

typedef enum Operator
{Add, Subtract, Multiply, Divide} operator;

void CalcInit();
double GetInput();
int GetOperator();
double Calculate();

double num1;
double num2;
operator Operator;
double result;

int main() {
    int continueCalc = 1;
    while (continueCalc)
    {    
        CalcInit();
        printf("\nTry again? (1 for yes, any other input for no.): ");
        getchar();
        if (scanf("%d", &continueCalc) != true) {
            continueCalc = 0;
        }
    }
}

void CalcInit() {
    printf("\nWelcome To The Terminal Calculator!");
    printf("\nInput #1: ");
    num1 = GetInput(num1);
    printf("\nInput #2: ");
    num2 = GetInput(num2);
    printf("\nInputs: %.8g, %.8g\n", num1, num2);
    printf("Operator (Add = 0, Subtract = 1, Multiply = 2, Divide = 3): ");
    Operator = GetOperator(Operator);
    printf("Calculating...");
    result = Calculate();
    printf("\nThe result is: %.8g!",result);
}

double GetInput(double num) {
    if (scanf("%lf", &num) == false) {
        printf("Invalid input, try again.\n");
        getchar();
        GetInput(num);
    }
    return num;
}

int GetOperator(int num) {
    if (scanf("%d", &num) == false) {
        printf("Invalid input, try again.\n");
        getchar();
        GetOperator(num);
    }
    return num;
}

double Calculate() {
    if (Operator == Add) {return num1 + num2;}
    if (Operator == Subtract) {return num1 - num2;}
    if (Operator == Multiply) {return num1 * num2;}
    if (Operator == Divide) {return num1 / num2;}
    return 0;
}