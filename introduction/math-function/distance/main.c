#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    double xLength = x2 - x1;
    double yLength = y2 - y1;

    double xLenDouble = xLength * xLength;
    double yLenDouble = yLength * yLength;

    printf("%lf\n", sqrt(xLenDouble + yLenDouble));
}
