#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0;
    int high = n-1;
    int ans;

    while (low<=high) {
        int mid = (low + high) / 2;
        int miss = arr[mid] - (mid+1);
        if (miss < k) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    printf("%d", k+low);

    return 0;
}