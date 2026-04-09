#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height, x, y;
} Cell;

void swap(Cell *a, Cell *b) {
    Cell t = *a; *a = *b; *b = t;
}

void heapify_up(Cell heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].height > heap[i].height) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapify_down(Cell heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i+1, r = 2*i+2;

        if (l < size && heap[l].height < heap[smallest].height)
            smallest = l;
        if (r < size && heap[r].height < heap[smallest].height)
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void push(Cell heap[], int *size, Cell val) {
    heap[(*size)++] = val;
    heapify_up(heap, *size - 1);
}

Cell pop(Cell heap[], int *size) {
    Cell root = heap[0];
    heap[0] = heap[--(*size)];
    heapify_down(heap, *size, 0);
    return root;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int grid[R][C];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf("%d", &grid[i][j]);

    int visited[R][C];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            visited[i][j] = 0;

    Cell heap[R*C];
    int size = 0;

    // Push all boundary cells
    for (int i = 0; i < R; i++) {
        push(heap, &size, (Cell){grid[i][0], i, 0});
        push(heap, &size, (Cell){grid[i][C-1], i, C-1});
        visited[i][0] = visited[i][C-1] = 1;
    }
    for (int j = 0; j < C; j++) {
        push(heap, &size, (Cell){grid[0][j], 0, j});
        push(heap, &size, (Cell){grid[R-1][j], R-1, j});
        visited[0][j] = visited[R-1][j] = 1;
    }

    int water = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (size > 0) {
        Cell cur = pop(heap, &size);

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dirs[d][0];
            int ny = cur.y + dirs[d][1];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny]) {
                visited[nx][ny] = 1;

                if (cur.height > grid[nx][ny])
                    water += cur.height - grid[nx][ny];

                int newHeight = (cur.height > grid[nx][ny]) ? cur.height : grid[nx][ny];

                push(heap, &size, (Cell){newHeight, nx, ny});
            }
        }
    }

    printf("%d\n", water);
    return 0;
}