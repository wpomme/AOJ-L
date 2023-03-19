#include <iostream>
#include <memory>
#define NIL NULL

struct node{
  struct node *right;
  struct node *left;
  struct node *parent;
  int key;
};

typedef struct node *Node;

Node root;

Node treeMinimum(Node x){
  while (x->left != NIL) {
    x = x->left;
  }
  return x;
}

// Node treeMaximum(Node x){
// 
// 
// }
// 
//
Node treeSearch(Node u, int k){
  while (u != NIL) {
    if (u->key == k) {
      return u;
    } else if (u->key > k) {
      u = u->left;
    } else {
      u = u->right;
    }
  }

  return u;
}

Node treeSuccessor(Node x){
  if (x->right != NIL) {
    return treeMinimum(x->right);
  }

  Node y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}


void treeDelete(Node z){
  Node y; // node to be deleted
  Node x; // child of y

  // determine element y which is to be deleted.
  if (z->left == NIL || z->right == NIL) {
    y = z;
  } else {
    y = treeSuccessor(z);
  }

  // determine element which is a child of y. 
  if (y->left != NIL) {
    x = y->left;
  } else {
    x = y->right;
  }

  // set the parent of x.
  if (x != NIL) {
    x->parent = y->parent;
  }

  if (y->parent == NIL) {
    root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }

  if (y != z) {
    z->key = y->key;
  }

  // if (z->left == NIL && z->right == NIL) {
  //   if (z->parent->left->key == z->key) {
  //     z->parent->left = NIL;
  //   } else {
  //     z->parent->right = NIL;
  //   }
  // }

  // if (z->left != NIL && z->right != NIL) {
  //   z->key = y->key;
  //   treeDelete(y);
  // }

  // if (z->left == NIL && z->right != NIL) {
  //   x = z->left;
  //   if (z->parent->left->key == z->key) {
  //     z->parent->left = x;
  //     x->parent = z->parent;
  //   } else {
  //     z->parent->right = x;
  //     x->parent = z->parent;
  //   }
  // }

  // if (z->left != NIL && z->right == NIL) {
  //   x = z->right;
  //   if (z->parent->left->key == z->key) {
  //     z->parent->left = x;
  //     x->parent = z->parent;
  //   } else {
  //     z->parent->right = x;
  //     x->parent = z->parent;
  //   }
  // }
}

void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;

  // z = malloc(sizeof(struct node));
  z = new node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == NIL) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

void inorder(Node u){
  if (u == NIL) return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node u){
  if (u == NIL) return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}


int main(){
  int n;
  char com[20];
  scanf("%d", &n);

  for (int i = 0; i < n; i++ ){
    int x;
    scanf("%s", com);

    switch (com[0]) {
      case 'i':
        scanf("%d", &x);
        insert(x);
        break;
      case 'p':
        inorder(root);
        printf("\n");
        preorder(root);
        printf("\n");
        break;
      case 'd':
        scanf("%d", &x);
        treeDelete(treeSearch(root, x));
        break;
      case 'f':
        scanf("%d", &x);
        Node t = treeSearch(root, x);
        if ( t != NIL ) printf("yes\n");
        else printf("no\n");
        break;
    }
  }
}
