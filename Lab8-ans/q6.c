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

    int *heap = (int *)malloc(n * n * sizeof(int));
    int size = 0;

    int visited[100000] = {0};

    insert(heap, &size, 2);
    insert(heap, &size, 5);
    insert(heap, &size, 7);

    visited[2] = visited[5] = visited[7] = 1;
    int next, curr;

    for (int p=0; p<n; p++) {
        curr = heap[0];
        remove_min(heap, &size);

        next = curr*2;
        if (!visited[next]) {
            insert(heap, &size, next);
            visited[next] = 1;
        }
        next = curr*5;
        if (!visited[next]) {
            insert(heap, &size, next);
            visited[next] = 1;
        }
        next = curr*7;
        if (!visited[next]) {
            insert(heap, &size, next);
            visited[next] = 1;
        }
    }

    // remove_min(heap, &size);
    printf("%d", curr);

    free(heap);

    return 0;
}