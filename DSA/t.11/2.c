#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int treeHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Total number of nodes: %d\n", countNodes(root));
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));
    printf("Height of the tree: %d\n", treeHeight(root));

    return 0;
}

