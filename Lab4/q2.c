#include <stdio.h>

void sort(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        for (int j = start; j < end - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int index = 0;
    int k = 1;
    int max = n-1;

    while (index <= max) {
        int size = k;
        if (index + size -1 > max) {
            size = max - index + 1;
        }

        if (k%2==1) {
            sort(arr, index, index + size - 1);
            index += size;
        } else {
            sort(arr, max-size+1, max);
            max -= size;
        }

        k++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

