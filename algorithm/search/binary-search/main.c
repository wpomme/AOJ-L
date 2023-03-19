#include <stdio.h>

int main() {

    // Input standard input data
    // n: 5
    // s: 1 2 3 4 5 (s is sorted array)
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

    // binary search
    int counter = 0;

    for (int i = 0; i < q; i++) {
        int left = 0;
        int right = n;

        while (left < right) {
            int mid = (left + right) / 2;
            if (s[mid] == t[i]) {
                counter++;
                break;
            } else if (t[i] < s[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    printf("%d\n", counter);
}
