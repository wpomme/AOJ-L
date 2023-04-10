#include <stdio.h>
#include <string.h>

int main() {
    int taroPoint = 0;
    int hanakoPoint = 0;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char taroCards[1000], hanakoCards[1000];
        scanf("%s %s", taroCards, hanakoCards);
        int result = strcmp(taroCards, hanakoCards);
        if (result == 0) {
            taroPoint++;
            hanakoPoint++;
        } else if (result > 0) {
            taroPoint += 3;
        } else {
            hanakoPoint += 3;
        }
    }

    printf("%d %d\n", taroPoint, hanakoPoint);
}
