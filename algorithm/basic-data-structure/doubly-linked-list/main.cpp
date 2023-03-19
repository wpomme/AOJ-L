#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
  long long key;
  Node *next;
  Node *prev;
};

Node* nil;

Node* listSearch(long long key){
  // write
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void init(){
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  Node *cur = nil->next;
  int isf = 0;
  while(cur != nil){
    // if ( cur == nil ) break;
    if ( isf++ > 0)  printf(" ");
    printf("%lld", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node* t){
  // write
  if ( t == nil ) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst(){
  Node* t = nil->next;
  // if ( t == nil ) return;
  deleteNode(t);
}

void deleteLast(){
  Node* t = nil->prev;
  // if ( t == nil ) return;
  deleteNode(t);
}

void deleteKey(long long key){
  // delete list search key
  deleteNode(listSearch(key));
}


void insert(long long key){
  Node* x = (Node *)malloc(sizeof(Node));
  x->key = key;

  // write
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main(){
  long long key;
  int n;
  // int size = 0;
  char command[20];
  // int np = 0, nd = 0;

  scanf("%d", &n);
  init();

  for (int i = 0; i < n; i++ ) {
    scanf("%s%lld", command, &key);

    switch (command[0]) {
      case 'i':
        insert(key);
        // np++;
        // size++;
        break;
      case 'd':
        if (strlen(command) > 6) {
          if ( command[6] == 'F' ) {
            deleteFirst();
          } else if ( command[6] == 'L' ) {
            deleteLast();
          }
        } else {
          deleteKey(key);
          // nd++; 
        }
      // size--;
    }
  }

  // printList();

  Node *cur = nil->next;
  while (cur != nil) {
    printf("%lld%c", cur->key, cur->next == nil ? '\n' : ' ');
    cur = cur->next;
  }

  return 0;
}
