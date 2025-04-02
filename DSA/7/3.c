#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prv;
} node;

node* convert(int arr[], int size) {
    node *head = NULL, *temp = NULL;
    for (int i = 0; i < size; i++) {
        node *nnode = (node*)malloc(sizeof(node));
        nnode->data = arr[i];
        nnode->next = NULL;
        nnode->prv = NULL;

        if (head == NULL) {
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            nnode->prv = temp;
            temp = nnode;
        }
    }
    return head;
}

void print(node *head) {
    node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* insert_first(node *head) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = 10;
    newnode->next = head;
    newnode->prv = NULL;

    if (head) {
        head->prv = newnode;
    }

    return newnode;
}

node* insert_end(node *head) {
    if (head == NULL) {
        return insert_first(head);
    }
    node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = 10;
    newnode->next = NULL;
    newnode->prv = temp;

    temp->next = newnode;
    return head;
}

node* insert_kth(node *head, int k) {
    if (k == 1) {
        return insert_first(head);
    }

    node *temp = head;
    int count = 1;
    
    while (temp && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (!temp || !temp->next) {
        return insert_end(head);
    }

    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = 10;
    newnode->next = temp->next;
    newnode->prv = temp;

    if (temp->next) {
        temp->next->prv = newnode;
    }
    temp->next = newnode;

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = convert(arr, size);

    int n = -1;
    while (n != 0) {
        printf("\n0 - Exit\n1 - Insert at Start\n2 - Insert at End\n3 - Insert at Position\n");
        printf("Enter choice: ");
        scanf("%d", &n);

        switch (n) {
            case 0:
                printf("Program ends\n");
                break;
            case 1:
                head = insert_first(head);
                print(head);
                break;
            case 2:
                head = insert_end(head);
                print(head);
                break;
            case 3:
                printf("Enter position: ");
                int k;
                scanf("%d", &k);
                head = insert_kth(head, k);
                print(head);
                break;
            default:
                printf("Invalid input, try again!\n");
        }
    }
    return 0;
}
