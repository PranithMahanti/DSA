#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int A[n1];
    for (int i=0; i<n1; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &n2);
    int B[n2];
    for (int i=0; i<n2; i++) {
        scanf("%d", &B[i]);
    }

    int C[n1+n2];
    int i=0, j=0, k=0;
    for (; (i<n1 && j<n2); k++) {
        if (A[i] <= B[j]) {
            C[k] = A[i++];
        }
        else {
            C[k] = B[j++];
        }
        // else {
        //     C[k] = A[i];
        //     i++;
        //     j++;
        // }
    }

    for (; i<n1; i++, k++) {
        C[k] = A[i];
    }

    for (; j<n2; j++, k++) {
        C[k] = B[j];
    }

    for (int m=0; m<n1+n2; m++) {
        printf("%d ", C[m]);
    }
    printf("\n");
}