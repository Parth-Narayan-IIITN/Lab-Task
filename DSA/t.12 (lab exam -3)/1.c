#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int q1[MAX], q2[MAX], q3[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;
int front3 = 0, rear3 = -1;

void push(int queue[], int *rear, int x) {
    queue[++(*rear)] = x;
}

int pop(int queue[], int *front) {
    return queue[(*front)++];
}

int size(int front, int rear) {
    return rear - front + 1;
}

int front(int queue[], int front) {
    return queue[front];
}

int empty(int front, int rear) {
    return front > rear;
}

void reverse() {
    while (!empty(front1, rear1) || !empty(front2, rear2)) {
        int p = size(front1, rear1);
        for (int i = 1; i < p; i++) {
            int x = pop(q1, &front1);
            push(q2, &rear2, x);
        }
        int x = pop(q1, &front1);
        push(q3, &rear3, x);

        int q = size(front2, rear2);
        for (int i = 1; i < q; i++) {
            int x = pop(q2, &front2);
            push(q1, &rear1, x);
        }
        if (!empty(front2, rear2)) {
            int y = pop(q2, &front2);
            push(q3, &rear3, y);
        }
    }
}

int main() {
    int n;
    printf("Enter the elements : \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(q1, &rear1, x);
    }

    reverse();

    while (!empty(front3, rear3)) {
        int x = pop(q3, &front3);
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
