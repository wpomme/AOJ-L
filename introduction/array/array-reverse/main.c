#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int a[N];
    int r[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; i++) {
        r[i] = a[N - 1 - i];
    }


    for (int i = 0; i < N; i++) {
        printf("%d", r[i]);
        if (i != N - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
