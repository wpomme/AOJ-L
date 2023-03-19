#include <iostream>
#define HEAP_SIZE 2000000
#define INFTY (1<<30)

using namespace std;

long long heap[HEAP_SIZE + 1];
int heapSize = 1;

void maxHeapify(int i) {
  int left = 2 * i;
  int right = 2 * i + 1;
  int largest;

  if (left <= heapSize && heap[left] > heap[i]) {
    largest = left;
  } else {
    largest = i;
  }

  if (right <= heapSize && heap[right] > heap[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(heap[i], heap[largest]);
    maxHeapify(largest);
  }
}

void heapIncreaseKey(int size, long long key) {
    heap[size] = key;
    while (size > 1 && (heap[size / 2] < heap[size])) {
        swap(heap[size], heap[size / 2]);
        size = size / 2;
    }
}

void insert(int key) {
    heapSize++;
    heap[heapSize] = -INFTY;
    heapIncreaseKey(heapSize, key);
}

int heapExtractMax() {
    if (heapSize < 1) return -INFTY;
    long long heapMax = heap[1];
    heap[1] = heap[heapSize--];
    maxHeapify(1);
    return heapMax;
}

int main() {

    while (1) {
        char command[8];
        int v;
        scanf("%s %i", command, &v);

        switch (command[2]) {
            // insert
            case 's':
                insert(v);
                break;
            // extract
            case 't':
                printf("%d\n", heapExtractMax());
                break;
            // end
            default:
                return 0;
        }
    }
}
