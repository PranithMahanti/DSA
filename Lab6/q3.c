#include <stdio.h>
#define MAX 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int largestRectangle(int heights[], int n) {
    int stack[MAX];
    int top = -1;
    int maxArea = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int height = heights[stack[top--]];
            int width;

            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            maxArea = max(maxArea, height * width);
        }
    }

    while (top != -1) {
        int height = heights[stack[top--]];
        int width;

        if (top == -1)
            width = i;
        else
            width = i - stack[top] - 1;

        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);

    int heights[MAX];

    for (int i = 0; i < n; i++)
        scanf("%d", &heights[i]);

    printf("%d", largestRectangle(heights, n));

    return 0;
}
