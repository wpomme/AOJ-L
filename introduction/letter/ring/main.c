#include <stdio.h>
#include <string.h>
#define LETTER_SIZE 100

int main() {
    char ring[LETTER_SIZE * 2];
    char buffer[LETTER_SIZE * 2];
    char pstr[LETTER_SIZE];

    scanf("%s %s", ring, pstr);

    strcpy(buffer, ring);
    strcat(ring, buffer);

    strstr(ring, pstr) != NULL ? printf("Yes\n") : printf("No\n");
}

