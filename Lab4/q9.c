#include <stdio.h>

struct Interval {
    int start;
    int end;
};

/* Sort intervals by start ascending, then end ascending */
void sortIntervals(struct Interval arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].start < arr[min].start ||
               (arr[j].start == arr[min].start &&
                arr[j].end < arr[min].end)) {
                min = j;
            }
        }
        if (min != i) {
            struct Interval temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    /* Step 1: Sort intervals */
    sortIntervals(arr, n);

    /* Print sorted intervals */
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }

    /* Step 2: Check contiguity */
    if (n == 1) {
        printf("Contiguous\n");
        return 0;
    }

    int current_end = arr[0].end;
    int fragmented = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].start > current_end) {
            fragmented = 1;
            break;
        }
        if (arr[i].end > current_end) {
            current_end = arr[i].end;
        }
    }

    if (fragmented)
        printf("Fragmented\n");
    else
        printf("Contiguous\n");

    return 0;
}
