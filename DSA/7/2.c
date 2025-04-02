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
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* delete_start(node *head) {
    if (head == NULL) return NULL;
    node *temp = head;
    head = head->next;
    if (head) head->prv = NULL;
    free(temp);
    return head;
}

node* delete_tail(node *head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    if (temp->prv) temp->prv->next = NULL;
    free(temp);
    return head;
}

node* delete_pos(node *head, int k) {
    if (head == NULL || (head->next == NULL && k == 1)) {
        free(head);
        return NULL;
    }

    if (k == 1) return delete_start(head);

    node *temp = head;
    int count = 1;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return head; 

    if (temp->next == NULL) return delete_tail(head); 

    node *prevNode = temp->prv;
    node *nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prv = prevNode;
    free(temp);

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = convert(arr, size);

    int n = -1;
    while (n != 0) {
        printf("0 - Exit\n1 - Delete at Start\n2 - Delete at End\n3 - Delete at Position\n");
        printf("Enter choice: ");
        scanf("%d", &n);

        switch (n) {
            case 0:
                printf("Program ends\n");
                break;
            case 1:
                head = delete_start(head);
                print(head);
                break;
            case 2:
                head = delete_tail(head);
                print(head);
                break;
            case 3:
                printf("Enter position: ");
                int k;
                scanf("%d", &k);
                head = delete_pos(head, k);
                print(head);
                break;
            default:
                printf("Invalid input, try again!\n");
        }
    }
    return 0;
}
