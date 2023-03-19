#include <stdio.h>
#define SENTINEL 1000000001

void merge(int array[], int left, int mid, int right);
void mergeSort(int array[], int left, int right);
int counter = 0;

int main() {
    int n;
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    mergeSort(array, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d%c", array[i], i != n - 1 ? ' ' : '\n');
    }
    printf("%d\n", counter);
}

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int leftArray[n1];
    int rightArray[n2];

    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + i];
    }

    leftArray[n1] = SENTINEL;
    rightArray[n2] = SENTINEL;
    int i = 0, j = 0;

    for (int k = left; k < right; k++) {
        counter++;
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
    }
}

void mergeSort(int array[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        merge(array, left, mid, right);
    }
}
