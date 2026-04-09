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

int countRange(Node* root, int L, int R) {
    if (!root) return 0;

    if (root->data < L)
        return countRange(root->right, L, R);

    if (root->data > R)
        return countRange(root->left, L, R);

    return 1 + countRange(root->left, L, R)
             + countRange(root->right, L, R);
}

int main() {
    return 0;
}