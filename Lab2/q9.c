#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

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

    int even=0, odd=0;

    for (int k=0; k<n; k++) {
        if (k%2==0) {
            if (A[k]%2==0) {
                even++;
            }
        } else {
            if(A[k]%2==1) {
                odd++;
            }
        }
    }

    printf("%d, %d\n", even, odd);

    return 0;
}