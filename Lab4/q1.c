#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[r][c];

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int target;
    scanf("%d", &target);

    int row=0; 
    int col = c-1;

    while (row<r && col>=0) {
        if (mat[row][col] == target) {
            break;
        } 
        if (mat[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }

    if (mat[row][col] == target) {
        printf("%d %d\n", row, col);
    } else {
        printf("-1");
    }

    return 0;

}