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

void merge(Node* head_1, Node* head_2) {
    if (head_1 == NULL) {
        print(head_2);
        return;
    }
    if (head_2 == NULL) {
        print(head_1);
        return;
    }

    Node* temp = head_1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head_2;

    temp = head_1;
    int v[1000], n = 0; 
    while (temp) {
        v[n++] = temp->data;
        temp = temp->next;
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    temp = head_1;
    for (int i = 0; i < n; i++) {
        temp->data = v[i];
        temp = temp->next;
    }

    print(head_1);
}

int main() {
    int arr1[] = {53,56,31,2,78,};
    int arr2[] = {72,6,0,1,44};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node* head_1 = cvt_arr2ll(arr1, size1);
    Node* head_2 = cvt_arr2ll(arr2, size2);

    merge(head_1, head_2);

    return 0;
}
