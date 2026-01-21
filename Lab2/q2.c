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

struct Node* segregateEvenOdd(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;

    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }

    // If no even elements
    if (evenHead == NULL)
        return oddHead;

    // Join even and odd lists
    evenTail->next = oddHead;

    // Important: terminate list
    if (oddTail != NULL)
        oddTail->next = NULL;

    return evenHead;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node *head = NULL, *tail = NULL;

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

    head = segregateEvenOdd(head);

    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}
