#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert a node at the end of the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// add two linked lists
struct Node* addLinkedLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node** temp = &result;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        appendNode(temp, sum % 10);
        temp = &((*temp)->next);
    }
    return result;
}

// print
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;
    
    // first list
    appendNode(&l1, 2);
    appendNode(&l1, 4);
    appendNode(&l1, 3);
    
    // second list
    appendNode(&l2, 5);
    appendNode(&l2, 6);
    appendNode(&l2, 4);
    
    printf("First List: ");
    printList(l1);
    printf("Second List: ");
    printList(l2);
    
    // adding
    struct Node* result = addLinkedLists(l1, l2);
    
    printf("Resultant List: ");
    printList(result);
    
    return 0;
}
