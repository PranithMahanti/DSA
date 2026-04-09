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

Node* successor(Node* root, int x) {
    Node* succ = NULL;

    while (root) {
        if (x < root->data) {
            succ = root;
            root = root->left;
        } else
            root = root->right;
    }
    return succ;
}

int main() {
    return 0;
}