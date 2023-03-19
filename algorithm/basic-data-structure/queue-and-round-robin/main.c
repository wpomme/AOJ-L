#include <stdio.h>
#include <stdlib.h>
#define LEN 100005
#define MAX LEN

// Process (ex: P2 80)
typedef struct pp{
  char name[100];
  int t;
}P;

// Queue and head, tail, number
P Q[LEN];
int head, tail, n;

void initialize() {
    head = tail = 0;
}

int isEmpty() {
    return head == tail;
}

int isFull() {
    return head == (tail + 1) % MAX;
}

void enqueue(P x){
    if (isFull()) {
        printf("Error: overflowing queue.\n");
        exit(1);
    }

    Q[tail] = x;

    if (tail + 1 == MAX) {
        tail = 0;
    } else {
        tail++;
    }
}

P dequeue(){
    P x;
    if (isEmpty()) {
        printf("Error: underflowing queue.\n");
    }

    x = Q[head];

    if (head + 1 == MAX) {
        head = 0;
    } else {
        head++;
    }

    return x;
}


int main(){
  // c = counter?
  int elaps = 0;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);

  initialize();

  for ( i = 0; i < n; i++){
    // enqueueing from standard input
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
    tail++;
  }

  // Round Robin
  while (!isEmpty()) {
    u = dequeue();
    // Treat Process
    if (u.t <= q) {
        elaps += u.t;
        printf("%s %d\n", u.name, elaps);
        continue;
    }

    elaps += q;
    u.t = u.t - q;

    enqueue(u);
  }
  
  return 0;
}
