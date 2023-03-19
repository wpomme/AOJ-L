#include <stdio.h>
#include <ctype.h>
#define ALPHA_SIZE 26
#define LOWER_A 97

int main() {
    char ch;
    int count[ALPHA_SIZE];

    for (int i = 0; i < ALPHA_SIZE; i++) {
        count[i] = 0;
    }

    while (scanf("%c", &ch) != EOF) {
        if (islower(ch)) {
            int num = ch - 'a';
            count[num]++;
        }
        if (isupper(ch)) {
            int num = ch - 'A';
            count[num]++;
        }
    }

    for (int i = 0; i < ALPHA_SIZE; i++) {
        int int_a = LOWER_A + i;
        char c = int_a;
        printf("%c : %d\n", c, count[i]);
    }
}
