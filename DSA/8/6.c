#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char arr[100], brr[100];
int top = -1;

void push(char c) {
    if (top < 99) {
        top++;
        arr[top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

void pop() {
    if (top != -1) {
        top--;
    } else {
        printf("There is no element to remove\n");
    }
}

char top1() {
    if (top != -1) {
        return arr[top];
    } else {
        return '\0'; // Returning a null character to indicate empty stack
    }
}

bool convert() {
    for (int i = 0; i < strlen(brr); i++) {
        if (brr[i] == '(' || brr[i] == '[' || brr[i] == '{') {
            push(brr[i]);
        } 
        else if (brr[i] == ')' || brr[i] == ']' || brr[i] == '}') {
            if (top == -1) return false; // If stack is empty, it's unbalanced
            
            char topChar = top1();
            if ((brr[i] == ')' && topChar == '(') ||
                (brr[i] == ']' && topChar == '[') ||
                (brr[i] == '}' && topChar == '{')) {
                pop();
            } else {
                return false;
            }
        }
    }
    
    return (top == -1); // If stack is empty, it's balanced
}

int main() {
    printf("Enter the parentheses: ");
    scanf("%s", brr);
    
    if (convert()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
