#include <stdio.h>

/*
 * p -> the first element of array
 * r -> the last element of array
 */
int partition(int *array, int p, int r);
void swap(int *array, int p, int q);

int main() {
    int n;
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int p = partition(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i == p) {
            printf("[%d]%c", array[i], i != n - 1 ? ' ' : '\n');
        } else {
            printf("%d%c", array[i], i != n - 1 ? ' ' : '\n');
        }
    }
}

int partition(int *array, int p, int r) {
    int value = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (array[j] <= value) {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, r);
    return i + 1;
}

void swap(int *array, int p, int q) {
    int tmp = array[p];
    array[p] = array[q];
    array[q] = tmp;
}
