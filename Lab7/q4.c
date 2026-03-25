#include <stdio.h>

#define MAX 10

typedef struct {
    int row;
    int col;
    int dist;
} Node;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int grid[MAX][MAX];
    int visited[MAX][MAX] = {0};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &grid[i][j]);

    // Directions: Up, Down, Left, Right
    int drow[] = {-1, 1, 0, 0};
    int dcol[] = {0, 0, -1, 1};

    Node queue[MAX * MAX];
    int front = 0, rear = 0;

    // Start from (0,0)
    queue[rear++] = (Node){0, 0, 1};
    visited[0][0] = 1;

    while (front < rear) {
        Node current = queue[front++];
        int r = current.row;
        int c = current.col;
        int d = current.dist;

        // If target found
        if (grid[r][c] == 2) {
            printf("%d\n", d);
            return 0;
        }

        // Explore 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            // Boundary + valid check
            if (nr >= 0 && nr < M &&
                nc >= 0 && nc < N &&
                !visited[nr][nc] &&
                grid[nr][nc] != 1) {

                visited[nr][nc] = 1;
                queue[rear++] = (Node){nr, nc, d + 1};
            }
        }
    }

    return 0;
}