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

int floorBST(Node* root, int x) {
    int floor = -1;

    while (root) {
        if (root->data == x)
            return x;
        if (root->data > x)
            root = root->left;
        else {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

int main() {
    return 0;
}