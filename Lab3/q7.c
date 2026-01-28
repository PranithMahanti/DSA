#include <stdio.h>

void sort(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
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
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int index = 0;
    int groupSize = 1;

    while (index < n) {
        int size = groupSize;
        if (index + size > n) {
            size = n - index;
        }

        sort(arr, index, index + size - 1);

        index += size;
        groupSize++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
