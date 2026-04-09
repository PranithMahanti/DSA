#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int list_idx;
    int elem_idx;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void heapify_up(Node heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].value > heap[i].value) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapify_down(Node heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i+1, r = 2*i+2;

        if (l < size && heap[l].value < heap[smallest].value)
            smallest = l;
        if (r < size && heap[r].value < heap[smallest].value)
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void push(Node heap[], int *size, Node val) {
    heap[(*size)++] = val;
    heapify_up(heap, *size - 1);
}

Node pop(Node heap[], int *size) {
    Node root = heap[0];
    heap[0] = heap[--(*size)];
    heapify_down(heap, *size, 0);
    return root;
}

int main() {
    int K;
    scanf("%d", &K);

    int lists[K][1000];
    int sizes[K];

    for (int i = 0; i < K; i++) {
        scanf("%d", &sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &lists[i][j]);
        }
    }

    Node heap[K];
    int size = 0;

    int current_max = INT_MIN;

    // Initialize heap
    for (int i = 0; i < K; i++) {
        push(heap, &size, (Node){lists[i][0], i, 0});
        if (lists[i][0] > current_max)
            current_max = lists[i][0];
    }

    int range_start = 0, range_end = INT_MAX;

    while (1) {
        Node cur = pop(heap, &size);

        int current_min = cur.value;

        // Update best range
        if (current_max - current_min < range_end - range_start) {
            range_start = current_min;
            range_end = current_max;
        }

        int i = cur.list_idx;
        int j = cur.elem_idx;

        // If this list ends then stop
        if (j + 1 == sizes[i])
            break;

        int next_val = lists[i][j + 1];

        push(heap, &size, (Node){next_val, i, j + 1});

        if (next_val > current_max)
            current_max = next_val;
    }

    printf("%d %d\n", range_start, range_end);

    return 0;
}