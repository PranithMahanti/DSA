#include <stdio.h>

int main() {
    int n;
    long long G;
    scanf("%d %lld", &n, &G);

    int income[n];
    long long total_income = 0;
    int max_income = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &income[i]);
        total_income += income[i];
        if (income[i] > max_income)
            max_income = income[i];
    }

    // If even taxing everyone fully is not enough
    if (total_income < G) {
        printf("-1\n");
        return 0;
    }

    int low = 0, high = max_income;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long collected = 0;

        for (int i = 0; i < n; i++) {
            if (income[i] <= mid)
                collected += income[i];
            else
                collected += mid;
        }

        if (collected >= G) {
            ans = mid;
            high = mid - 1;   // try smaller cap
        } else {
            low = mid + 1;    // cap too small
        }
    }

    printf("%d\n", ans);
    return 0;
}
