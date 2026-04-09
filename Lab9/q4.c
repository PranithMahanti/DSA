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

#define MAX 1000

struct Stack{
    int arr[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX-1;
}

int pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return 0;
    }
    return s->arr[(s->top)--];
}

void push(struct Stack *s, int value) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

void zigzag(Node* root) {
    if (!root) return;

    Stack s1, s2;
    push(&s1, root);

    while (!isEmpty(s1) || !isEmpty(s2)) {
        while (!isEmpty(s1)) {
            Node* temp = pop(&s1);
            printf("%d ", temp->data);

            if (temp->left) push(&s2, temp->left);
            if (temp->right) push(&s2, temp->right);
        }
        while (!isEmpty(s2)) {
            Node* temp = pop(&s2);
            printf("%d ", temp->data);

            if (temp->right) push(&s1, temp->right);
            if (temp->left) push(&s1, temp->left);
        }
    }
}

int main() {
    return 0;
}