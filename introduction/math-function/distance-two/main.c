#include <stdio.h>
#include <math.h>

double difference1(double x, double y) {
    return x < y ? y - x : x - y;
}

double difference2(double x, double y) {
    if (x < y) {
        double diff = y - x;
        return diff * diff;
    } else {
        double diff = x - y;
        return diff * diff;
    }
}

double difference3(double x, double y) {
    if (x < y) {
        double diff = y - x;
        return diff * diff * diff;
    } else {
        double diff = x - y;
        return diff * diff * diff;
    }
}

double difference_inf(double x, double y) {
    // same to difference1
    return x < y ? y - x : x - y;
}

int main(void) {
    int n;
    scanf("%d", &n);

    double x[1000];
    double y[1000];

    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    // one dimension
    double diff1[1000];
    double solution1 = 0;

    for (int i = 0; i < n; i++) {
        diff1[i] = difference1(x[i], y[i]);
        solution1 += diff1[i];
    }

    // two dimension
    double diff2[1000];
    double solution2 = 0;

    for (int i = 0; i < n; i++) {
        diff2[i] = difference2(x[i], y[i]);
        solution2 += diff2[i];
    }

    solution2 = sqrt(solution2);

    // three dimension
    double diff3[1000];
    double solution3 = 0;

    for (int i = 0; i < n; i++) {
        diff3[i] = difference3(x[i], y[i]);
        solution3 += diff3[i];
    }

    solution3 = pow(solution3, 1.0 / 3.0);

    // infinity dimension
    double solution_inf = 0;

    for (int i = 0; i < n; i++) {
        double tmp = difference_inf(x[i], y[i]);
        if (solution_inf < tmp) {
            solution_inf = tmp;
        }
    }

    printf("%lf\n", solution1);
    printf("%lf\n", solution2);
    printf("%lf\n", solution3);
    printf("%lf\n", solution_inf);
}
