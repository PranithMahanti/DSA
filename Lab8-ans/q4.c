#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sum;
    int i, j;
} Node;

// Min heap swap
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapify_up(Node heap[], int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p].sum > heap[idx].sum) {
            swap(&heap[p], &heap[idx]);
            idx = p;
        } else break;
    }
}

// Heapify down
void heapify_down(Node heap[], int size, int idx) {
    while (1) {
        int smallest = idx;
        int l = 2*idx + 1, r = 2*idx + 2;

        if (l < size && heap[l].sum < heap[smallest].sum)
            smallest = l;
        if (r < size && heap[r].sum < heap[smallest].sum)
            smallest = r;

        if (smallest != idx) {
            swap(&heap[idx], &heap[smallest]);
            idx = smallest;
        } else break;
    }
}

// Insert
void push(Node heap[], int *size, Node val) {
    heap[(*size)++] = val;
    heapify_up(heap, *size - 1);
}

// Pop
Node pop(Node heap[], int *size) {
    Node root = heap[0];
    heap[0] = heap[--(*size)];
    heapify_down(heap, *size, 0);
    return root;
}

// Check visited
int visited[1005][1005];

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int A[n1], B[n2];
    for (int i = 0; i < n1; i++) scanf("%d", &A[i]);
    for (int j = 0; j < n2; j++) scanf("%d", &B[j]);

    int K;
    scanf("%d", &K);

    Node heap[100000];
    int size = 0;

    // start with (0,0)
    push(heap, &size, (Node){A[0] + B[0], 0, 0});
    visited[0][0] = 1;

    int count = 0;

    while (count < K && size > 0) {
        Node cur = pop(heap, &size);
        int i = cur.i, j = cur.j;

        printf("%d %d\n", A[i], B[j]);
        count++;

        // (i+1, j)
        if (i + 1 < n1 && !visited[i+1][j]) {
            push(heap, &size, (Node){A[i+1] + B[j], i+1, j});
            visited[i+1][j] = 1;
        }

        // (i, j+1)
        if (j + 1 < n2 && !visited[i][j+1]) {
            push(heap, &size, (Node){A[i] + B[j+1], i, j+1});
            visited[i][j+1] = 1;
        }
    }

    return 0;
}