#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int deadline, reward;
} Job;

// Comparator for sorting by deadline
int cmp(const void *a, const void *b) {
    return ((Job *)a)->deadline - ((Job *)b)->deadline;
}

// ---------- Min Heap ----------
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify_up(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapify_down(int heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i+1, r = 2*i+2;

        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r < size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void push(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    heapify_up(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify_down(heap, *size, 0);
    return root;
}

// ---------- MAIN ----------
int main() {
    int n;
    scanf("%d", &n);

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].deadline, &jobs[i].reward);
    }

    // Step 1: Sort by deadline
    qsort(jobs, n, sizeof(Job), cmp);

    int heap[n];
    int size = 0;

    // Step 2: Process jobs
    for (int i = 0; i < n; i++) {
        push(heap, &size, jobs[i].reward);

        if (size > jobs[i].deadline) {
            pop(heap, &size); // remove smallest reward
        }
    }

    // Step 3: Sum remaining rewards
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += heap[i];
    }

    printf("%d\n", total);
    return 0;
}