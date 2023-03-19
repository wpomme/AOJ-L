#include <stdio.h>
#include <stdlib.h>
#define MAX 100005

int top;
int stack[MAX];

void initialize() {
    top = 0;
}

int isEmpty() {
    return top == 0;
}

int isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Error: underflow\n");
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Error: overflow\n");
    }
    top--;
    return stack[top + 1];
}

int main() {
    char s[100];

    while(scanf("%s", s) != EOF){
        int p1, p2;
        switch (s[0]) {
            case '+':
                p1 = pop();
                p2 = pop();
                push(p2 + p1);
                break;
            case '-':
                p1 = pop();
                p2 = pop();
                push(p2 - p1);
                break;
            case '*':
                p1 = pop();
                p2 = pop();
                push(p2 * p1);
                break;
            default:
                push(atoi(s));
                break;
        }
    }

    printf("%d\n", pop());
}
