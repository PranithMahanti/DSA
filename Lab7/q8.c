#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define SIZE 100

int main() {
    int N;
    scanf("%d", &N);

    char queue[MAX][SIZE];
    int front = 0, rear = 0;

    strcpy(queue[rear++], "1");

    for (int i = 0; i < N; i++) {

        char current[SIZE];
        strcpy(current, queue[front++]);

        printf("%s ", current);

        char next0[SIZE], next1[SIZE];

        strcpy(next0, current);
        strcat(next0, "0");

        strcpy(next1, current);
        strcat(next1, "1");

        strcpy(queue[rear++], next0);
        strcpy(queue[rear++], next1);
    }

    return 0;
}