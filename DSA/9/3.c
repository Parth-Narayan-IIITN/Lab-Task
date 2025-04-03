#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (!stack->top) {
        printf("Stack Underflow\n");
        return -1; 
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int peek(struct Stack* stack) {
    if (stack->top) {
        return stack->top->data;
    }
    printf("Stack is Empty\n");
    return -1;
}

void display(struct Stack* stack) {
    struct Node* temp = stack->top;
    if (!temp) {
        printf("Stack is empty\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    printf("Pushing elements to Stack 1:\n");
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    display(&stack1);

    printf("\nPushing elements to Stack 2:\n");
    push(&stack2, 100);
    push(&stack2, 200);
    push(&stack2, 300);
    display(&stack2);

    printf("\nPopping from Stack 1: %d\n", pop(&stack1));
    display(&stack1);

    printf("\nPopping from Stack 2: %d\n", pop(&stack2));
    display(&stack2);

    return 0;
}
