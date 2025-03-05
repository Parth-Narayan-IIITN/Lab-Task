#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* cvt_arr2ll(int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;

    Node* mover = head;
    for (int i = 1; i < size; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = NULL;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void even_odd(Node* head) {
    if (head == NULL || head->next == NULL) return;

    Node* odd = head;
    Node* even = head->next;
    Node* odd_ck = odd;
    Node* even_ck = even;

    while (odd && even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        if (odd) {
            even->next = odd->next;
            even = even->next;
        }
    }

    printf("Odd indexed nodes:\n");
    print(odd_ck);
    printf("Even indexed nodes:\n");
    print(even_ck);
}

int main() {
    int arr[] = {43, 5, 23, 7, 77, 34, 573, 91, 62};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = cvt_arr2ll(arr, size);
    printf("Original List:\n");
    print(head);

    even_odd(head);

    return 0;
}
