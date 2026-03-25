#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int queue[1000];
    int front =0, rear = 0;

    for (int i=0; i<n; i++) {
        scanf("%d", &queue[rear++]);
    }

    int stack[k];
    int top = 0;

    for (int i=0; i<k; i++) {
        stack[top++] = queue[front++];
    }

    for (int i=0; i<k; i++) {
        queue[rear++] = stack[--top];
    }

    for (int i=0; i<n-k; i++) {
        queue[rear++] = queue[front++];
    }

    for (int i=0; i<n; i++) {
        printf("%d ", queue[front++]);
    }
    printf("\n");

    return 0;
}