#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = newNode(val);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int X;
    scanf("%d", &X);

    struct Node* notX_head = NULL;
    struct Node* notX_tail = NULL;
    struct Node* X_head = NULL;
    struct Node* X_tail = NULL;

    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* next = curr->next;
        curr->next = NULL;

        if (curr->data == X) {
            if (X_head == NULL)
                X_head = X_tail = curr;
            else {
                X_tail->next = curr;
                X_tail = curr;
            }
        } else {
            if (notX_head == NULL)
                notX_head = notX_tail = curr;
            else {
                notX_tail->next = curr;
                notX_tail = curr;
            }
        }

        curr = next;
    }

    if (notX_head == NULL)
        head = X_head;
    else {
        notX_tail->next = X_head;
        head = notX_head;
    }

    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}
