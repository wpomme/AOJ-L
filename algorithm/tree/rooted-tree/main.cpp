#include <iostream>
#include <vector>
#define MAX 100005
#define NIL -1

using namespace std;

struct Node {
  int parent;
  int left;
  int right;
};

struct Node tree[MAX];

string rootedTreeType(Node u) {
  if (u.parent == NIL) {
    return "root";
  }

  if (u.left == NIL) {
    return "leaf";
  }

  return "internal node";
}

int getDepth(Node u) {
  if (u.parent == NIL) {
    return 0;
  }

  return getDepth(tree[u.parent]) + 1;
}

void printChildrenList(Node u) {
  vector<int> sibling;
  int next = u.left;
  while (next != NIL) {
    sibling.push_back(next);
    next = tree[next].right;
  }

  cout << "[";
  for (auto s : sibling) {
    if (sibling.back() == s) {
      cout << s;
    } else {
      cout << s << ", ";
    }
  }
  cout << "]";
}

void print(int index, Node u) {
  printf("node %d: parent = %d, depth = %d, ", index, u.parent, getDepth(u));
  cout << rootedTreeType(u) << ", ";
  printChildrenList(u);
  printf("\n");
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    tree[i].parent = tree[i].left = tree[i].right = NIL;
  }

  for (int i = 0; i < n; i++) {
    int node, c;
    cin >> node >> c;
    vector<int> children(c);

    for (int j = 0; j < c; j++) {
      cin >> children.at(j);

      if (j == 0) {
        tree[node].left = children.at(j);
      } else {
        tree[children.at(j - 1)].right = children.at(j);
      }

      tree[children.at(j)].parent = node;
    }
  }

  for (int i = 0; i < n; i++) {
    print(i, tree[i]);
  }
}
