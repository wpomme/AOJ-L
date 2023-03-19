#include <stdio.h>

char hash = '#';
char comma = '.';

void printChessBoard(int height, int width) {
    char oddRow[width], evenRow[width];
    for (int i = 0; i < width; i++) {
        if ((i % 2) == 0) {
            oddRow[i] = hash;
            evenRow[i] = comma;
        } else {
            oddRow[i] = comma;
            evenRow[i] = hash;
        }
    }
    for (int i = 0; i < height; i++) {
        if ((i % 2) == 0) {
            for (int j = 0; j < width; j++) {
                printf("%c", oddRow[j]);
            }
        } else {
            for (int j = 0; j < width; j++) {
                printf("%c", evenRow[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        int h, w;
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0) return 0;
        printChessBoard(h, w);
        printf("\n");
    }
}
