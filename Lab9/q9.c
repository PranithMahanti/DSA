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

int blackHeight(Node* root) {
    int height = 0;
    while (root) {
        if (root->color == BLACK)
            height++;
        root = root->left; // any path works
    }
    return height;
}

int main() {
    return 0;
}