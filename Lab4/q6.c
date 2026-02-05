#include <stdio.h>

/* Counts how many elements <= x in a sorted row */
int countLE(int row[], int c, int x) {
    int low = 0, high = c - 1;
    int ans = c;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int mat[R][C];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int low = mat[0][0], high = mat[0][C - 1];

    for (int i = 1; i < R; i++) {
        if (mat[i][0] < low)
            low = mat[i][0];
        if (mat[i][C - 1] > high)
            high = mat[i][C - 1];
    }

    int desired = (R * C) / 2;

    while (low <= high) {
        int mid = (low + high) / 2;
        int count = 0;

        for (int i = 0; i < R; i++) {
            count += countLE(mat[i], C, mid);
        }

        if (count <= desired)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("%d\n", low);
    return 0;
}
