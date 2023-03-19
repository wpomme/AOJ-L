#include <stdio.h>
#define VALUE_MAX 10000

void countingSort(int *input, int *output, int valueMax, int length, int *counter);
int min(int a, int b);

int main() {
    int n;
    scanf("%d", &n);
    int input[n + 1];
    int output[n + 1];
    int counter[VALUE_MAX + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i + 1]);
        output[i] = 0;
    }

    for (int i = 0; i < VALUE_MAX + 1; i++) {
        counter[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        counter[input[i + 1]]++;
    }

    countingSort(input, output, VALUE_MAX, n, counter);

    for (int i = 1; i < n + 1; i++) {
        printf("%d%c", output[i], i == n ? '\n' : ' ');
    }
}

void countingSort(int *input, int *output, int valueMax, int length, int *counter) {
    for (int i = 1; i < valueMax; i++) {
        counter[i] = counter[i] + counter[i - 1];
    }

    for (int i = 1; i < length + 1; i++) {
        output[counter[input[i]]] = input[i];
        counter[input[i]]--;
    }
}

int min(int a, int b) {
    return a > b ? b : a;
}
