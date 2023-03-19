#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[101][101];

    // scan value
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // calculate matrix[i][c]
    for (int i = 0; i < r; i++) {
        int acc = 0;
        for (int j = 0; j < c; j++) {
            acc += matrix[i][j];
        }
        matrix[i][c] = acc;
    }

    // calculate matrix[r][j]
    for (int j = 0; j < c; j++) {
        int acc = 0;
        for (int i = 0; i < r; i++) {
            acc += matrix[i][j];
        }
        matrix[r][j] = acc;
    }

    // calculate matrix[r][c]
    {
        int acc = 0;
        for (int j = 0; j < c; j++) {
            acc += matrix[r][j];
        }
        matrix[r][c] = acc;
    }

    // display matrix[i][j]
    for (int i = 0; i < r + 1; i++) {
        for (int j = 0; j < c + 1; j++) {
            printf("%d%c", matrix[i][j], j == c ? '\n' : ' ');
        }
    }
}
