#include <stdio.h>

int canShip(int weights[], int n, int D, int cap) {
    int days = 1;
    int load = 0;

    for (int i = 0; i < n; i++) {
        if (load + weights[i] <= cap) {
            load += weights[i];
        } else {
            days++;
            load = weights[i];
        }
    }

    return days <= D;
}

int main() {
    int n, D;
    scanf("%d %d", &n, &D);

    int weights[n];
    int max = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
        if (weights[i] > max)
            max = weights[i];
        sum += weights[i];
    }

    int low = max, high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canShip(weights, n, D, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
