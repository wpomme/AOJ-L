#include <stdio.h>
#include <math.h>

long gcd(long a, long b);

int main() {
    long a, b;
    scanf("%ld %ld", &a, &b);

    long result = 0;

    result = gcd(a, b);
    printf("%ld\n", result);
}

long gcd(long a, long b) {

    if (b == 0) return a;

    if (a > b) {
        return gcd(b, a % b);
    } else {
        return gcd(a, b % a);
    }
}
