#include <iostream>
#define MAX 100000

using namespace std;

int main() {
  int n;
  cin >> n;

  int heap[MAX + 1];

  for (int i = 1; i < n + 1; i++) cin >> heap[i];

  for (int i = 1; i < n + 1; i++) {
    int parent, left, right;
    parent = i / 2;
    left = 2 * i;
    right = 2 * i + 1;
    printf("node %d: key = %d, ", i, heap[i]);
    if (parent != 0) printf("parent key = %d, ", heap[parent]);
    if (left < n + 1) printf("left key = %d, ", heap[left]);
    if (right < n + 1) printf("right key = %d, ", heap[right]);
    printf("\n");
  }
}
