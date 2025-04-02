#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int evaluatePostfix(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');  // Convert char to int
        } else {
            int b = pop();
            int a = pop();

            switch (expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': 
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    push(a / b);
                    break;
                default:
                    printf("Invalid Operator\n");
                    return -1;
            }
        }
    }
    return pop();  // Final result
}

int main() {
    char expr[MAX];
    
    printf("Enter postfix expression: ");
    scanf("%s", expr);
    
    int result = evaluatePostfix(expr);
    
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    
    return 0;
}
