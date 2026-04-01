#include <stdio.h>

struct Val {
    int strength;
    int value;
};

void merge(struct Val arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Val L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].strength < R[j].strength ||
            (L[i].strength == R[j].strength &&
            L[i].value < R[j].value)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(struct Val arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int strength(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Val arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].strength = strength(arr[i].value);
    }

    mergeSort(arr, 0, n-1);

    for (int i=n-1; i>=0; i--) {
        printf("%d ", arr[i].value);
    }

    printf("\n");
    return 0;
}