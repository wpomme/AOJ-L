#include <stdio.h>

int cardTypeMap(char type) {
    switch (type) {
        case 'S':
            return 0;
        case 'H':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        default:
            return -1;
    }
}

char cardNumberMap(int n) {
    switch (n) {
        case 0:
            return 'S';
        case 1:
            return 'H';
        case 2:
            return 'C';
        case 3:
            return 'D';
        default:
            return 'E';
    }
}

int main() {
    int n;
    int cards[4][13];

    scanf("%d", &n);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        char type;
        // char newline;
        int num;
        // if (i > 0) {
        //     scanf("%c", &newline);
        // }
        scanf(" %c %d", &type, &num);
        cards[cardTypeMap(type)][num - 1] = 1;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (cards[i][j] == 0) {
                printf("%c %d\n", cardNumberMap(i), j + 1);
            }
        }
    }
}
