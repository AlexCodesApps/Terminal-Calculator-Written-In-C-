#include <stdio.h>

#ifndef bool
typedef enum Boolean
{false = 0, true = 1} 
bool;
#endif

typedef enum Operator
{Add, Subtract, Multiply, Divide, Power} operator;

void CalcInit();
void CalcInit2(double fResults);
double GetInput();
int GetOperator();
double Calculate();
double Pow();

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
            getchar();
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
    printf("Operator (Add = 0, Subtract = 1, Multiply = 2, Divide = 3, Pow = 4): ");
    Operator = GetOperator(Operator);
    printf("Calculating...");
    result = Calculate();
    printf("\nThe result is: %.8g!",result);
}

void CalcInit2(double fResults) {
    printf("\nWelcome To The Terminal Calculator!");
    printf("\nInput #1: %lf", fResults);
    num1 = fResults;
    printf("\nInput #2: ");
    num2 = GetInput(num2);
    printf("\nInputs: %.8g, %.8g\n", num1, num2);
    printf("Operator (Add = 0, Subtract = 1, Multiply = 2, Divide = 3, Pow = 4): ");
    Operator = GetOperator(Operator);
    printf("Calculating...");
    result = Calculate();
    printf("\nThe result is: %.8g!",result);

}

double GetInput(double num) {
    if (scanf("%lf", &num) == (false)) {
        printf("Invalid input, try again.\n");
        getchar();
        GetInput(num);
    }
    return num;
}

int GetOperator(int num) {
    bool valid = (scanf("%d", &num));
    if (valid == false || num > 4 || num < 0) {
        printf("Invalid input, try again.\n");
        int num2;
        GetOperator(num);
    }
    return num;
}

double Calculate() {
    if (Operator == Add) {return num1 + num2;}
    if (Operator == Subtract) {return num1 - num2;}
    if (Operator == Multiply) {return num1 * num2;}
    if (Operator == Divide) {return num1 / num2;}
    if (Operator == Power) {return Pow(num1, num2);}
    return 0;
}

double Pow(double num, double pow) {
    double result = num;
    if (pow > 0) {
        for (int i = 1; i < pow; i++)
        {
            result *= num;
        }
    }
    else if (pow < 0)
        for (int i = 1; i > pow; i--)
        {
            result *= 1/num;
        }
    else result = 1;
    return result;
}
