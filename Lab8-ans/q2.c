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

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *heap = (int *)malloc(n * sizeof(int));
    int size = 0;

    for (int i = 0; i < n; i++) {
        insert(heap, &size, arr[i]);
    }

    int cost = 0;
    while (1) {
        int a = heap[0];
        remove_min(heap, &size);
        int b = heap[0];
        remove_min(heap, &size);

        int c = a + b;
        cost += c;

        insert(heap, &size, c);

        if (size == 1) {
            break;
        }

    }

    printf("%d\n", cost);

    free(arr);
    free(heap);

    return 0;
}