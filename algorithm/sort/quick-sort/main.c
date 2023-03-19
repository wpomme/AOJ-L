#include <stdio.h>
#define SENTINEL 1000000001

typedef struct _card {
    char type;
    int number;
} Card;

/* partition
 * @param p -> the first element of array
 * @param r -> the last element of array
 */
int partition(Card *array, int p, int r);
void swap(Card *array, int p, int q);
void quicksort(Card *array, int p, int r);

void merge(Card array[], int left, int mid, int right);
void mergeSort(Card array[], int left, int right);

int main() {
    int n;
    scanf("%d", &n);
    Card arr1[n];
    Card arr2[n];
    int isStable = 1;

    char s[2];
    int v;
    for (int i = 0; i < n; i++) {
        // %c でなく%s にする
        scanf("%s %d", s, &v);
        arr1[i].type = arr2[i].type = s[0];
        arr1[i].number = arr2[i].number = v;
    }

    quicksort(arr1, 0, n - 1);
    mergeSort(arr2, 0, n);

    for (int i = 0; i < n; i++) {
        if (arr1[i].type != arr2[i].type) isStable = 0;
    }

    if (isStable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%c %d\n", arr1[i].type, arr1[i].number);
    }
}

int partition(Card *array, int p, int r) {
    int value = array[r].number;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (array[j].number <= value) {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, r);
    return i + 1;
}

void swap(Card *array, int p, int q) {
    Card tmp = array[p];
    array[p] = array[q];
    array[q] = tmp;
}

void quicksort(Card *array, int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);
        quicksort(array, p, q - 1);
        quicksort(array, q + 1, r);
    }
}

void merge(Card *array, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    Card leftArray[n1];
    Card rightArray[n2];

    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + i];
    }

    leftArray[n1].number = SENTINEL;
    rightArray[n2].number = SENTINEL;

    int i = 0, j = 0;

    for (int k = left; k < right; k++) {
        if (leftArray[i].number <= rightArray[j].number) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
    }
}

void mergeSort(Card array[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        merge(array, left, mid, right);
    }
}
