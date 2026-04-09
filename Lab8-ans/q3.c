#include <stdio.h>
#include <stdlib.h>

// ---------- MAX HEAP (for left) ----------
void max_heapify_up(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] < heap[i]) {
            int t = heap[p]; heap[p] = heap[i]; heap[i] = t;
            i = p;
        } else break;
    }
}

void max_heapify_down(int heap[], int size, int i) {
    while (1) {
        int largest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            int t = heap[i]; heap[i] = heap[largest]; heap[largest] = t;
            i = largest;
        } else break;
    }
}

void max_insert(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    max_heapify_up(heap, *size - 1);
}

int max_pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    max_heapify_down(heap, *size, 0);
    return root;
}

// ---------- MIN HEAP (for right) ----------
void min_heapify_up(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            int t = heap[p]; heap[p] = heap[i]; heap[i] = t;
            i = p;
        } else break;
    }
}

void min_heapify_down(int heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
            i = smallest;
        } else break;
    }
}

void min_insert(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    min_heapify_up(heap, *size - 1);
}

int min_pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    min_heapify_down(heap, *size, 0);
    return root;
}

// ---------- MAIN ----------
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int left[n], right[n]; // max-heap, min-heap
    int lsize = 0, rsize = 0;

    for (int i = 0; i < n; i++) {
        int x = arr[i];

        // Step 1: Insert
        if (lsize == 0 || x <= left[0])
            max_insert(left, &lsize, x);
        else
            min_insert(right, &rsize, x);

        // Step 2: Balance
        if (lsize > rsize + 1)
            min_insert(right, &rsize, max_pop(left, &lsize));
        else if (rsize > lsize)
            max_insert(left, &lsize, min_pop(right, &rsize));

        // Step 3: Median
        if (lsize == rsize)
            printf("%.1f ", (left[0] + right[0]) / 2.0);
        else
            printf("%.1f ", (float)left[0]);
    }

    return 0;
}