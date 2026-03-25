#include <stdio.h>

#define MAX 1000

int main() {

    int n;
    scanf("%d", &n);

    int seq1[MAX], seq2[MAX];
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++)
        scanf("%d", &seq1[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &seq2[i]);

    char operations[2 * MAX][10];  // store operations
    int opCount = 0;

    int j = 0;  // pointer for seq2

    for (int i = 0; i < n; i++) {

        stack[++top] = seq1[i];
        sprintf(operations[opCount++], "Push");

        while (top >= 0 && stack[top] == seq2[j]) {
            top--;
            sprintf(operations[opCount++], "Pop");
            j++;
        }
    }

    if (j != n) {
        printf("Impossible");
    } else {
        for (int i = 0; i < opCount; i++) {
            printf("%s\n", operations[i]);
        }
    }

    return 0;
}
