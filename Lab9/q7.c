#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int count = 0;

void kth(Node* root, int k, int* result) {
    if (!root) return;

    kth(root->left, k, result);

    count++;
    if (count == k) {
        *result = root->data;
        return;
    }

    kth(root->right, k, result);
}

int main() {
    return 0;
}