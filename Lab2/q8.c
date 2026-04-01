#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[n], B[n+2];
    int visitedA[999] = {0};
    int visitedB[999] = {0};

    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
        visitedA[A[i]] += 1;
    }

    for (int i=0; i<n+2; i++) {
        scanf("%d", &B[i]);
        visitedB[B[i]] += 1;
    }

    for (int i = 0; i < n + 2; i++) {
        int val = B[i];
        if (visitedB[val] > visitedA[val]) {
            printf("%d ", val);
            visitedB[val]--;
        }
    }
    printf("\n");

    return 0;
}