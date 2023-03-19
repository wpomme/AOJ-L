#include <stdio.h>
#define MAX 100005
#define NIL -1

typedef struct _node {
    int parent, left, right;
} Node;

Node tree[MAX];

void preParse(int n) {
    if (n == NIL) return;
    printf(" %d", n);
    preParse(tree[n].left);
    preParse(tree[n].right);
}

void inParse(int n) {
    if (n == NIL) return;
    inParse(tree[n].left);
    printf(" %d", n);
    inParse(tree[n].right);
}

void postParse(int n) {
    if (n == NIL) return;
    postParse(tree[n].left);
    postParse(tree[n].right);
    printf(" %d", n);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) tree[i].parent = -1;

    for (int i = 0; i < n; i++) {
        int node, l, r;
        scanf("%d %d %d", &node, &l, &r);
        tree[node].left = l;
        tree[node].right = r;
        if (l != NIL) tree[l].parent = node;
        if (r != NIL) tree[r].parent = node;
    }

    int root = NIL;
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == NIL) {
            root = i;
            break;
        }
    }

    printf("Preorder\n");
    preParse(root);
    printf("\n");

    printf("Inorder\n");
    inParse(root);
    printf("\n");

    printf("Postorder\n");
    postParse(root);
    printf("\n");
}
