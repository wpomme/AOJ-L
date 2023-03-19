#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count[4][3][10];

    // init count array
    for (int b = 0; b < 4; b++) {
        for (int f = 0; f < 3; f++) {
            for (int r = 0; r < 10; r++) {
                count[b][f][r] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int b, f, r, v;
        scanf("%d %d %d %d", &b, &f, &r, &v);
        count[b - 1][f - 1][r - 1] += v;
    }

    for (int b = 0; b < 4; b++) {
        for (int f = 0; f < 3; f++) {
            for (int r = 0; r < 10; r++) {
                printf(" %d", count[b][f][r]);
                if (r == 9) printf("\n");
            }
        }
        if (b != 3) printf("####################\n");
    }
}
