#include <stdio.h>
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

int peek(struct Stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}


int main() {
    struct Stack mainStack, minStack;
    init(&mainStack);
    init(&minStack);

    int n;
    scanf("%d", &n);

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);

            push(&mainStack, x);

            if (isEmpty(&minStack) || x <= peek(&minStack)) {
                push(&minStack, x);
            }
        }

        else if (op == 2) {
            if (isEmpty(&mainStack)) {
                printf("Stack Empty\n");
            } else {
                int popped = pop(&mainStack);
                printf("Popped: %d\n", popped);

                if (popped == peek(&minStack)) {
                    pop(&minStack);
                }
            }
        }

        else if (op == 3) {
            if (isEmpty(&minStack)) {
                printf("Stack Empty\n");
            } else {
                printf("Minimum: %d\n", peek(&minStack));
            }
        }

        else if (op == 4) {
            if (isEmpty(&mainStack)) {
                printf("Stack Empty\n");
            } else {
                printf("Top: %d\n", peek(&mainStack));
            }
        }
    }

    return 0;
}