#include <stdio.h>
#define MAX_DIGIT 1000

int getSumOfNumber(char numbers[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += numbers[i] - '0';
    }
    return result;
}

int main() {
    char numbers[MAX_DIGIT];
    int index = 0;

    while(1) {
        scanf("%c", &numbers[index]);
        if (numbers[0] == '0') break;
        if (numbers[index] == '\n') {
            printf("%d\n", getSumOfNumber(numbers, index));
            index = 0;
        } else {
            index++;
        }
    }

}
