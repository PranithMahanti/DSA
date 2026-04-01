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

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* add = newNode(current->data + current->next->data);
        add->next = current->next->next;
        current->next->next = add;

        current = add->next;
    }

    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}
