#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int result = 0;
    char word[10];
    char input[50];

    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    while(1) {
        scanf("%s", input);

        if (strcmp(input, "END_OF_TEXT") == 0) {
            break;
        }

        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, word) == 0) {
            result++;
        }
    }

    printf("%d\n", result);
}
