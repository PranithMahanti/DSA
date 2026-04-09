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

Node* find(Node* root, int x) {
    if (!root || root->data == x) return root;

    if (x < root->data)
        return find(root->left, x);
    else
        return find(root->right, x);
}

int subtreeSum(Node* root) {
    if (!root) return 0;
    return root->data + subtreeSum(root->left) + subtreeSum(root->right);
}

int main() {
    return 0;
}