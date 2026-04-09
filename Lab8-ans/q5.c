#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapify_down(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}


void insert(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapify_up(heap, *size - 1);
}


void remove_min(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify_down(heap, *size, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * n * sizeof(int));
    for (int i = 0; i < n*n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    int *heap = (int *)malloc(n * n * sizeof(int));
    int size = 0;

    for (int i = 0; i < n*n; i++) {
        insert(heap, &size, arr[i]);
    }

    for (int p=0; p<k-1; p++) {
        remove_min(heap, &size);
    }

    printf("%d", heap[0]);

    free(arr);
    free(heap);

    return 0;
}