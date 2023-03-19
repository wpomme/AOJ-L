#include <stdio.h>
#define DIM_MAX 101

int main() {
    int n, m, l;
    long multiplicand[DIM_MAX][DIM_MAX];
    long multiplier[DIM_MAX][DIM_MAX];
    long products[DIM_MAX][DIM_MAX];

    scanf("%d %d %d", &n, &m, &l);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%ld", &multiplicand[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%ld", &multiplier[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < l; k++) {
            long acc = 0;
            for (int j = 0; j < m; j++) {
                acc += multiplicand[i][j] * multiplier[j][k];
            }
            products[i][k] = acc;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < l; k++) {
            printf("%ld%c", products[i][k], k == l - 1 ? '\n' : ' ');
        }
    }
}
