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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children: Get inorder successor
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int search(struct Node* root, int value) {
    if (root == NULL)
        return 0;
    if (value == root->data)
        return 1;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int elements[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(elements)/sizeof(elements[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, elements[i]);

    printf("Inorder traversal (sorted): ");
    inorder(root);
    printf("\n");

    int key = 60;
    if (search(root, key))
        printf("Element %d found in BST.\n", key);
    else
        printf("Element %d not found in BST.\n", key);
        
    root = deleteNode(root, 30);
    printf("After deleting 30, inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
