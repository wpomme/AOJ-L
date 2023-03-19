#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);

    int hours = s / 3600;
    int minutes = (s % 3600) /  60;
    int seconds = s % 60;

    printf("%d:%d:%d\n", hours, minutes, seconds);
}
