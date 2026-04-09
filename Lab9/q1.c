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

Node* LCA(Node* root, int u, int v) {
    if (root == NULL) return NULL;

    if (u < root->data && v < root->data)
        return LCA(root->left, u, v);
    if (u > root->data && v > root->data)
        return LCA(root->right, u, v);

    return root;
}

int main() {
    return 0;
}