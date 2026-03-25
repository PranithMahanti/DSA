#include <stdio.h>
#define MAX 1000

int result(int inp[], int n, int res[]) {
    int stack[MAX];
    int top = -1;

    for (int i=0; i<n; i++) {
        while (top >= 0 && inp[i] > inp[stack[top]]) {
            int prevIndex = stack[top--];
            res[prevIndex] = i - prevIndex;
        }

        stack[++top] = i;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int inp[n];
    int res[n];
    
    for (int i=0; i<n; i++) {
        scanf("%d", &inp[i]);
    }

    for (int i = 0; i < n; i++)
        res[i] = 0;

    result(inp, n, res);

    for (int i=0; i<n; i++) {
        printf("%d ", res[i]);
    }

    printf("\n");
    return 0;
}