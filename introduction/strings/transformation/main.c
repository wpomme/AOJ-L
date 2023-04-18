#include <stdio.h>

char str[1000];

void printStr(int a, int b) {
    for (int i = a; i <= b; i++) {
        printf("%c", str[i]);
        if (i == b) printf("\n");
    }
}

void reverseStr(int a, int b) {
    char buffer[1000];

    for (int i = 0; i < 1000; i++) {
        buffer[i] = '\0';
    }

    for (int i = 0; i <= b - a; i++) {
        buffer[i] = str[a + i];
        str[a + i] = '\0';
    }

    for (int i = 0; i <= b - a; i++) {
        str[a + i] = buffer[b - a - i];
    }
}

void replaceStr(int a, int b, char alternative[1000]) {
    for (int i = 0; i <= b - a; i++) {
        str[a + i] = alternative[i];
    }
}

int main() {
    int n;

    scanf("%s", str);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);

        int a, b;
        char alternative[1000];
        /*
         * command = 
         *   | replace
         *   | reverse
         *   | print
         */
        switch(command[2]) {
            case 'p':
                scanf("%d %d %s", &a, &b, alternative);
                replaceStr(a, b, alternative);
                break;
            case 'v':
                scanf("%d %d", &a, &b);
                reverseStr(a, b);
                break;
            case 'i':
                scanf("%d %d", &a, &b);
                printStr(a, b);
                break;
        }
    }
}
