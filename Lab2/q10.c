#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    int A[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i=0; i<n-1; i++) {
        int swapped=0;
        for (int j=0; j<n-i-1; j++) {
            if(A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped=1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    int max = 0, min = 0, elem = 0;

    for (int i=n-1; i>=0; i--) {
        max = A[i];
        min = max-k;

        int found = 0, currElem=0;
        for (int j=i; j>=0; j--) {
            if (A[j] == min) {
                found = 1;
                currElem = i-j+1;
            }
        }
        if (found) {
            if (currElem > elem) {
                elem = currElem;
            }
        }
    }

    printf("%d\n", elem);
    return 0;
    
}