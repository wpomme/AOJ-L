#include <iostream>
#define MAX 500000

using namespace std;

long heap[MAX + 1];

void maxHeapify(int i, int size) {
  int left = 2 * i;
  int right = 2 * i + 1;
  int largest = 0;

  if (left <= size && heap[left] > heap[i]) {
    largest = left;
  } else {
    largest = i;
  }

  if (right <= size && heap[right] > heap[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(heap[i], heap[largest]);

    maxHeapify(largest, size);
  }
}

void buildMaxHeap(int size) {
  for (int i = size / 2; i > 0; i--) {
    maxHeapify(i, size);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < n + 1; i++) cin >> heap[i];

  buildMaxHeap(n);

  for (int i = 1; i < n + 1; i++) {
    printf(" %ld", heap[i]);
  }
  printf("\n");
}
