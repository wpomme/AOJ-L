#include <stdio.h>
#include <math.h>


int main() {
    int a, b, deg;
    double rad;
    double PI = acos(-1);

    scanf("%d %d %d", &a, &b, &deg);
    rad = deg * PI / 180;
    
    double height = b * sin(rad); // h
    double area = a * height / 2; // S
    double perimeter = a + b + sqrt(a * a + b * b - 2 * a * b * cos(rad)); // L

    printf("%f\n%f\n%f\n", area, perimeter, height);
}
