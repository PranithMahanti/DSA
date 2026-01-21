#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* shift(struct Node* node) {
    struct Node* head = node;
    while(node->next != NULL) {
        node = node->next;
    }
    struct Node* newHead = head->next;
    node->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        struct Node* node = newNode(x);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int k;
    scanf("%d", &k);

    k = k%N;
    k = N-k;
    for (int i=0; i<k; i++) {
        head = shift(head);
    }

    struct Node* p = head;
    for (int i=0; i<N; i++) {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}