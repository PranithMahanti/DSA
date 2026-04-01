#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int ticket_queue[1000];
    int index_queue[1000];
    int front=0, rear=0;

    for (int i=0; i<n; i++) {
        scanf("%d", &ticket_queue[rear]);
        index_queue[rear] = i;
        rear++; 
    }

    int count = 0;

    while (front<rear) {
        int tick = --ticket_queue[front];
        count++;
        if (tick == 0 && index_queue[front] == k) {
            break;
        }
        if (tick > 0) {
            index_queue[rear] = index_queue[front];
            ticket_queue[rear] = tick;
            rear++;
        }
        front++;
    }

    printf("%d\n", count);

    return 0;
}