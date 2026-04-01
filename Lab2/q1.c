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

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    struct Node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverse(slow->next);
    struct Node* firstHalf = head;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return 0;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
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

    if (isPalindrome(head))
        printf("True");
    else
        printf("False");

    return 0;
}
