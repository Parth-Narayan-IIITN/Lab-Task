#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a circular linked list from an array
struct node* convert(int arr[], int size) {
    struct node *head = NULL, *temp = NULL;
    for (int i = 0; i < size; i++) {
        struct node *nnode = (struct node*)malloc(sizeof(struct node));
        nnode->data = arr[i];
        nnode->next = NULL;

        if (head == NULL) {
            head = nnode;
            temp = head;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
    }
    if (temp) temp->next = head; // Link last node to head to make it circular
    return head;
}

// Function to insert a node at different positions
struct node* change(struct node *head, int n, int x) {
    struct node *nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = x;

    struct node *temp = head;
    
    // Insert at beginning
    if (n == 0) {
        while (temp->next != head) {
            temp = temp->next;
        }
        nnode->next = head;
        temp->next = nnode;
        return nnode;
    }

    // Insert at end
    else if (n == -1) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = nnode;
        nnode->next = head;
        return head;
    }

    // Insert at nth position
    else {
        for (int i = 1; i < n - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        struct node *temp2 = temp->next;
        temp->next = nnode;
        nnode->next = temp2;
        return head;
    }
}

// Function to print circular linked list
void print(struct node *head) {
    if (!head) return;
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node *head = NULL;
    head = convert(arr, n);

    bool check = true;
    while (check) {
        printf("\n0 - Exit\n1 - Insert at Start\n2 - Insert at End\n3 - Insert at Position\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            check = false;
            printf("Program terminated.\n");
            break;
        }

        printf("Enter value to insert: ");
        int x;
        scanf("%d", &x);

        switch (choice) {
            case 1:
                head = change(head, 0, x);
                n++;
                print(head);
                break;
            case 2:
                head = change(head, -1, x);
                n++;
                print(head);
                break;
            case 3:
                printf("Enter the position (1 to %d): ", n + 1);
                int pos;
                scanf("%d", &pos);
                if (pos >= 1 && pos <= n + 1) {
                    head = change(head, pos, x);
                    n++;
                    print(head);
                } else {
                    printf("Invalid position! Position should be between 1 and %d.\n", n + 1);
                }
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
