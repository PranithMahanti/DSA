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

int countChildren(Node* root) {
    if (!root) return 0;
    int count = 0;
    if (root->left) count++;
    if (root->right) count++;
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* root = NULL;

    int arr[N];
    for (int i=0; i<N; i++) {
        scanf("%d", arr[N]);
        root = insert(root, arr[N]);
    }

    return 0;
}