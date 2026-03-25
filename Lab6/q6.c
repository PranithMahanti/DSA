#include <stdio.h>
#include <string.h>

#define MAX 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char str[]) {
    int stack[MAX];
    int top = -1;

    int maxLen = 0;

    stack[++top] = -1;

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == '(') {
            stack[++top] = i;
        }
        else {
            top--;

            if (top == -1) {
                stack[++top] = i;
            }
            else {
                int length = i - stack[top];
                maxLen = max(maxLen, length);
            }
        }
    }

    return maxLen;
}

int main() {
    char str[MAX];
    scanf("%s", str);

    printf("%d", longestValidParentheses(str));

    return 0;
}
