#include <iostream>
#define MAX 100005
#define NIL -1

using namespace std;

struct Node {
  int parent, left, right;
};

struct Node tree[MAX];

int getSibling(int index, Node u) {
  if (u.parent == NIL) return -1;
  return index == tree[u.parent].left ? tree[u.parent].right : tree[u.parent].left;
}

int getDegree(Node u) {
  int result = 0;
  if (u.left != NIL) result++;
  if (u.right != NIL) result++;
  return result;
}

int getDepth(Node u) {
  if (u.parent == NIL) return 0;
  return getDepth(tree[u.parent]) + 1;
}

int getHeight(Node u) {
  if (u.left == NIL && u.right == NIL) return 0;
  if (u.left == NIL) return 1 + getHeight(tree[u.right]);
  if (u.right == NIL) return 1 + getHeight(tree[u.left]);
  return max(1 + getHeight(tree[u.left]), 1 + getHeight(tree[u.right]));
}

string getTreeType(Node u) {
  if (u.parent == NIL) return "root";
  if (u.left == NIL && u.right == NIL) return "leaf";
  return "internal node";
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) tree[i].parent = -1;

  for (int i = 0; i < n; i++) {
    int node, l, r;
    cin >> node >> l >> r;
    tree[node].left = l;
    tree[node].right = r;
    if (l != NIL) tree[l].parent = node;
    if (r != NIL) tree[r].parent = node;
  }

  for (int i = 0; i < n; i++) {
    printf(
        "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
        i,
        tree[i].parent,
        getSibling(i, tree[i]),
        getDegree(tree[i]),
        getDepth(tree[i]),
        getHeight(tree[i]));
    cout << getTreeType(tree[i]) << endl;
  }
}
