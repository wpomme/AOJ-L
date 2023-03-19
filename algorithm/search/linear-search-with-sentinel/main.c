#include <stdio.h>

int main() {

    // Input standard input data
    // n: 5
    // s: 1 2 3 4 5
    // q: 3
    // t: 3 4 1

    int n;
    scanf("%d", &n);
    long long s[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }

    int q;
    scanf("%d", &q);
    long long t[q];

    for (int i = 0; i < q; i++) {
        scanf("%lld", &t[i]);
    }

    // linear search
    int counter = 0;

    for (int i = 0; i < q; i++) {
        long long key = t[i];
        s[n] = key;

        int j = 0;

        while (key != s[j]) {
            j++;
        }

        if (j != n) {
            counter++;
        }
    }

    printf("%d\n", counter);
}
