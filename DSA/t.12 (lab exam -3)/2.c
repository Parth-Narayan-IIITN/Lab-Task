#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void storeInorder(Node *root, int *arr, int *index) {
    if (root == NULL) return;
    storeInorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    storeInorder(root->right, arr, index);
}

int isPairPresent(Node *root, int target) {
    int arr[1000], index = 0;
    storeInorder(root, arr, &index);

    int left = 0, right = index - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            printf("Pair found: %d + %d = %d\n", arr[left], arr[right], target);
            return 1;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}

int main() {
    Node *root = NULL;
    int n, target, x;

    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    if (!isPairPresent(root, target)) {
        printf("No such pair exists.\n");
    }

    return 0;
}
