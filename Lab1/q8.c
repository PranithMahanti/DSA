#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int mat[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &mat[i]);
    }

    int direction = 0;
    scanf("%d", &direction);
    int shift = 0;
    scanf("%d", &shift);

    if (direction == 0) {
        for (int i=0; i<shift; i++) {
            int temp = mat[0];
            for (int k=0; k<n-1; k++) {
                mat[k] = mat[k+1];
            }
            mat[n-1] = temp;
        }
    } else {
        for (int i=0; i<shift; i++) {
            int temp = mat[n-1];
            for (int k=n-1; k>0; k--) {
                mat[k] = mat[k-1];
            }
            mat[0] = temp;
        }
    }

    for (int i=0; i<n; i++) {
        printf("%d ", mat[i]);
    }
    printf("\n");
}
