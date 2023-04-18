#include <stdio.h>
#include <math.h>

double calcDeviation(int n, int score[1000]) {
    double mean = 0;
    double variance = 0;

    // calc mean
    for (int i = 0; i < n; i++) {
        mean += score[i];
    }
    mean /= n;

    // calc variance
    for (int i = 0; i < n; i++) {
        variance += pow(score[i] - mean, 2);
    }
    variance /= n;

    return sqrt(variance);
}

int main() {
    while(1) {
        int n;
        int score[1000];

        scanf("%d", &n);

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            scanf("%d", &score[i]);
        }

        printf("%f\n", calcDeviation(n, score));
    }
}
