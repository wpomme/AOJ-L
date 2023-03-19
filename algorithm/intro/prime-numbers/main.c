#include <stdio.h>
#include <math.h>

const int TRUE = 1;
const int FALSE = 0;

int isPrime(int num);

int main() {
    int n;
    scanf("%d", &n);
    int num[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(num[i])) {
            counter++;
        }
    }

    printf("%d\n", counter);
}

int isPrime(int num) {
    if (num == 2) {
        return TRUE;
    }

    if (num < 2 || (num % 2) == 0) {
        return FALSE;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if ((num % i) == 0) return FALSE;
    }

    return TRUE;
}

