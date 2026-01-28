#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int low = 0; 
    int high = n-1;

    int mid;
    while (low<high) {
        mid = (low+high)/2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if (arr[low]==target) {
        printf("%d", low);
    } else {
        printf("-1");
    }
    return 0;
}