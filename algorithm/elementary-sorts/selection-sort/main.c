#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int counter = 0;

    for (int i = 0; i < N; i++) {
        int minj = i;

        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }

        if (minj != i) counter++;

        int aj = A[i];
        A[i] = A[minj];
        A[minj] = aj;
    }


    for (int i = 0; i < N; i++) {
        printf("%d%c", A[i], i == N - 1 ? '\n' : ' ');
    }

    printf("%d\n", counter);
}
