#include <stdio.h>
#define DIM_MAX 100

int main() {
    int n, m, l;
    int multiplicand[DIM_MAX][DIM_MAX];
    int multiplier[DIM_MAX][DIM_MAX];

    scanf("%d %d %d", &n, &m, &l);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &multiplicand[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &multiplier[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        int acc = 0;
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < l; k++) {
                acc += multiplicand[i][j] * multiplier[j][k];
            }
            printf("%d%c", acc, j - 1 == l ? '\n' : ' ');
        }
    }
}
