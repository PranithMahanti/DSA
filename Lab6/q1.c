#include <stdio.h>

#define MAX 1000

void calculateSpan(int price[], int n, int span[]) {
    int stack[MAX];
    int top = -1;

    stack[++top] = 0;
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (top >= 0 && price[stack[top]] <= price[i]) {
            top--;
        }

        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int price[MAX], span[MAX];

    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);

    calculateSpan(price, n, span);

    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);

    return 0;
}
