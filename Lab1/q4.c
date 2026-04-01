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

    printf("Union: ");

    int low = 0;
    int i=0, j=0;
    for (; (i<n1 && j<n2); ) {
        if (A[i] < B[j]) {
            printf("%d ", A[i++]);
        } 
        else if (A[i] > B[j]) {
            printf("%d ", B[j++]);
        } 
        else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }

    for (; i<n1; i++) {
        printf("%d ", A[i]);
    }

    for (; j<n2; j++) {
        printf("%d ", B[j]);
    }

    printf("\n");

    printf("Intersection: ");

    low = 0;
    i=0, j=0;
    for (; (i<n1 && j<n2); ) {
        if (A[i] < B[j]) {
            i++;
        } 
        else if (A[i] > B[j]) {
            j++;
        } 
        else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }

    printf("\n");
    
    return 0;
}