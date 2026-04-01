#include <stdio.h>
#include <ctype.h>

int isOp(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

double eval(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int main() {
    char str[1000];
    scanf("%s", str);

    double stack[1000];
    int top = -1;

    int i = 0;
    while (str[i] != '\0') {

        if (isdigit(str[i])) {
            stack[++top] = str[i] - '0';
        }
        else if (isOp(str[i])) {

            double b = stack[top--];  
            double a = stack[top--];  

            double res = eval(a, b, str[i]);
            stack[++top] = res;
        }

        i++;
    }

    printf("%.2lf", stack[top]);

    return 0;
}
