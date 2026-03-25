#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->arr[(s->top)--];
}

int peekStack(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->arr[s->top];
}

int main() {
    Stack stack1, stack2;
    init(&stack1);
    init(&stack2);

    int T;
    scanf("%d", &T);

    while (T--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int X;
            scanf("%d", &X);
            push(&stack1, X);
        }
        else if (type == 2) {
            // Dequeue
            if (isEmpty(&stack2)) {
                while (!isEmpty(&stack1)) {
                    push(&stack2, pop(&stack1));
                }
            }

            if (isEmpty(&stack2))
                printf("-1\n");
            else
                printf("%d\n", pop(&stack2));
        }
        else if (type == 3) {
            // Peek
            if (isEmpty(&stack2)) {
                while (!isEmpty(&stack1)) {
                    push(&stack2, pop(&stack1));
                }
            }

            if (isEmpty(&stack2))
                printf("-1\n");
            else
                printf("%d\n", peekStack(&stack2));
        }
    }

    return 0;
}