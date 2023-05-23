#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int elems[100];
    int top;
} Stack;

void initStack(Stack *S) {
    S->top = -1;
}

void push(Stack *S, int s) {
    S->top++;
    S->elems[S->top] = s;
}

int pop(Stack *S) {
    S->top--;
    return (S->elems[S->top + 1]);
}

int isOperand(char s) {
    return (s >= '0' && s <= '9');
}

int doOperator(char op, int x, int y) {
    int v = 0;
    switch (op) {
        case '+':
            v = x + y;
            break;
        case '-':
            v = x - y;
            break;
        case '*':
            v = x * y;
            break;
        case '/':
            v = x / y;
            break;
    }
    return (v);
}

void evaluate(char *eq) {
    Stack *S = (Stack *) malloc(sizeof(Stack));
    initStack(S);

    for (int i = 0; i < eq[i]; i++) {
        char s = eq[i];
        if (isOperand(s))
            push(S, s - '0');
        else {
            int a = pop(S);
            int b = pop(S);
            push(S, doOperator(s, b, a));
        }
    }
    printf("%d\n", pop(S));
}

int main() {
    int N;
    scanf("%d", &N);

    char eq[101];
    for (int i = 0; i < N; i++) {
        scanf("%s", eq);
        evaluate(eq);
    }

    return (0);
}