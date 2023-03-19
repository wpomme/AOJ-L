#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main() {
    int N;

    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int isOK = TRUE;
    int counter = 0;

    while (isOK) {
        isOK = FALSE;

        for (int j = N - 1; j > 0; j--) {
            if (A[j - 1] > A[j]) {
                counter++;
                int ai = A[j];
                A[j] = A[j - 1];
                A[j - 1] = ai;
                isOK = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d%c", A[i], i == N - 1 ? '\n' : ' ');
    }

    printf("%d\n", counter);
}
