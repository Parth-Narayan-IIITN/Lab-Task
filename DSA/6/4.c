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

Node* duplicate(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    int v[1000] = {0};
    int v1[1000], v1_size = 0;

    while (temp != NULL) {
        v[temp->data]++;  
        temp = temp->next;
    }

    for (int i = 0; i < 1000; i++) {
        if (v[i] > 0) {
            v1[v1_size++] = i;
        }
    }

    temp = head;
    for (int i = 0; i < v1_size; i++) {
        temp->data = v1[i];
        if (i < v1_size - 1) {
            temp = temp->next;
        }
    }
    temp->next = NULL;
    return head;
}

int main() {
    int arr[] = {5, 6, 3, 4, 6, 5, 3, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = cvt_arr2ll(arr, size);
    head = duplicate(head);
    print(head);

    return 0;
}
