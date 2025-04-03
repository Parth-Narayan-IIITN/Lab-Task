#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to add elements at the end of the linked list
struct node *element(struct node *head, int x) {
    struct node *temp = head;
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = x;
    nnode->next = NULL;
    if (head == NULL) {
        head = nnode;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = nnode;
    }
    return head;
}

struct node *convert(struct node *head, int k) {
    if (!head || k == 1) return head;

    struct node *temp = head, *p = NULL, *q = head, *r = NULL, *prevTail = NULL, *newHead = NULL;

    while (q) {
        struct node *segmentHead = q;
        struct node *segmentTail = NULL;
        for (int i = 0; i < k && q; i++) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
            if (i == 0) segmentTail = p; 
        }
        if (!newHead) {
            newHead = p;
        }
        if (prevTail) {
            prevTail->next = p;
        }

        segmentTail->next = q;
        prevTail = segmentTail;

        p = NULL;
    }
    return newHead;
}
void print(struct node *head) {
    struct node *temp = head;
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("No. of elements in the linked list: ");
    scanf("%d", &n);
    
    struct node *head = NULL;
    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        head = element(head, x);
    }

    int k;
    printf("Enter k (size of groups to reverse): ");
    scanf("%d", &k);

    printf("\nOld list:\n");
    print(head);
    
    head = convert(head, k);

    printf("\nNew list:\n");
    print(head);

    return 0;
}
