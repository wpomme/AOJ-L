#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long fib[n];

    fib[0] = 1;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("%ld\n", fib[n]);
}
