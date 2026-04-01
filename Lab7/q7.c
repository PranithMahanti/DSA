#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int gas[N], dist[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &gas[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &dist[i]);

    int totalGas = 0, totalDist = 0;
    for (int i = 0; i < N; i++) {
        totalGas += gas[i];
        totalDist += dist[i];
    }

    if (totalGas < totalDist) {
        printf("-1\n");
        return 0;
    }

    for (int start = 0; start < N; start++) {

        int fuel = 0;
        int count = 0;

        int index = start;

        while (count < N) {
            fuel += gas[index] - dist[index];

            if (fuel < 0)
                break;

            index = (index + 1) % N;
            count++;
        }

        if (count == N) {
            printf("%d\n", start);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}