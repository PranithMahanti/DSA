#include <stdio.h>

struct Val {
    int index;
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
        if (L[i].value <= R[j].value)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
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


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    struct Val arr[n];
    for (int i=0; i<n; i++) {
        arr[i].index = i;
        scanf("%d", &arr[i].value);
    }

    mergeSort(arr, 0, n-1);

    int i = 0;
    while (i < n) {
        int j = i;
        int minIdx = arr[i].index;
        int maxIdx = arr[i].index;

        while (j < n && arr[j].value == arr[i].value) {
            if (arr[j].index < minIdx) minIdx = arr[j].index;
            if (arr[j].index > maxIdx) maxIdx = arr[j].index;
            j++;
        }

        if (maxIdx - minIdx > k) {
            printf("%d %d\n", minIdx, maxIdx);
            return 0;
        }

        i = j;
    }

    printf("-1");
    return 0;
}