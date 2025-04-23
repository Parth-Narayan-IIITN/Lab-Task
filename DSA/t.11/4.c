#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int preorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int current = preorder[*preIndex];
    (*preIndex)++;
    struct Node* node = createNode(current);

    if (start == end) // Leaf node
        return node;

    int inIndex = search(inorder, start, end, current);

    node->left = buildTree(inorder, preorder, start, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, end, preIndex);

    return node;
}

void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    int preIndex = 0;

    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Constructed Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Constructed Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
