#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[1000];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int deque[1000];
    int front = 0, rear = -1;

    for (int i = 0; i < N; i++) {

        if (front <= rear && deque[front] <= i - K)
            front++;

        while (front <= rear && arr[deque[rear]] <= arr[i])
            rear--;

        deque[++rear] = i;

        if (i >= K - 1)
            printf("%d ", arr[deque[front]]);
    }

    return 0;
}