#include <stdio.h>
#include <ctype.h>
#define LETTER_SIZE 1200

int main() {
    char letter[LETTER_SIZE];
    int count = 0;

    while(1) {
        scanf("%c", &letter[count]);
        if (letter[count] == '\n') break;
        count++;
    }

    for (int i = 0; i < count; i++) {
        if (islower(letter[i])) {
            printf("%c", toupper(letter[i]));
            continue;
        }
        if (isupper(letter[i])) {
            printf("%c", tolower(letter[i]));
            continue;
        }
        printf("%c", letter[i]);
    }
    printf("\n");
}
