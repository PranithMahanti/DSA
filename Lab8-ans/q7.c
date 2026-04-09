#include <stdio.h>
#include <stdlib.h>

// Max heap functions
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify_up(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] < heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapify_down(int heap[], int size, int i) {
    while (1) {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
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

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char tasks[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &tasks[i]);
    }

    // Count frequencies
    int freq[26] = {0};
    for (int i = 0; i < n; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Build max heap
    int heap[26];
    int size = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            push(heap, &size, freq[i]);
    }

    int time = 0;

    while (size > 0) {
        int temp[26];
        int count = 0;
        int cycle = k + 1;

        while (cycle > 0 && size > 0) {
            int f = pop(heap, &size);
            f--;

            if (f > 0)
                temp[count++] = f;

            time++;
            cycle--;
        }

        // push remaining tasks back
        for (int i = 0; i < count; i++) {
            push(heap, &size, temp[i]);
        }

        // If heap still not empty → we had idle slots
        if (size > 0)
            time += cycle;
    }

    printf("%d\n", time);
    return 0;
}