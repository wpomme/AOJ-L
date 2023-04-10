#include <stdio.h>
#include <string.h>

void init_strings(char str[], int length) {
    for (int i = 0; i < length; i++) {
        str[i] = '\0';
    }
}

void trim_strings(char src[], int length, int h) {
    for (int i = 0; i < h; i++) {
        src[i] = '\0';
    }

    for (int i = 0; i < length - h; i++) {
        src[i] = src[i + h];
        src[i + h] = '\0';
    }
}

int main() {
    while(1) {
        char cards[200];
        scanf("%s", cards);
        int length = strlen(cards);

        if (cards[0] == '-') break;

        int times;
        char table[200];

        scanf("%d", &times);

        for (int i = 0; i < times; i++) {
            int h;
            scanf("%d", &h);

            init_strings(table, 200);
            strncpy(table, cards, h);
            trim_strings(cards, length, h);
            strcat(cards, table);
            init_strings(table, 200);
        }

        printf("%s\n", cards);
    }
}
