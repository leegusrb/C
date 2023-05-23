#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char elems[100];
    int top;
} Stack;

void initStack(Stack *S) {
    S->top = -1;
}

void push(Stack *S, char s) {
    S->top++;
    S->elems[S->top] = s;
}

char pop(Stack *S) {
    S->top--;
    return (S->elems[S->top + 1]);
}

char top(Stack *S) {
    return (S->elems[S->top]);
}

int isEmpty(Stack *S) {
    return (S->top == -1);
}

int isOperand(char s) {
    return (s >= 'A' && s <= 'Z');
}

int priority(char s) {
    switch (s) {
        case '(':
        case ')':
            return (0);
        case '|':
            return (1);
        case '&':
            return (2);
        case '<':
        case '>':
            return (3);
        case '-':
        case '+':
            return (4);
        case '/':
        case '*':
            return (5);
        default:
            return (6);
    }
}

void print(char c) {
    if (c == '|' || c == '&')
        printf("%c%c", c, c);
    else if (c == 'p')
        printf("+");
    else if (c == 'm')
        printf("-");
    else
        printf("%c", c);
}

void convert(char *eq) {
    Stack *S = (Stack *) malloc(sizeof(Stack));
    initStack(S);

    for (int i = 0; eq[i]; i++) {
        char s = eq[i];
        if (isOperand(s))
            print(s);
        else if (s == '(')
            push(S, s);
        else if (s == ')') {
            while (S->elems[S->top] != '(')
                print(pop(S));
            pop(S);
        } else if ((s == '+' || s == '-') && (i == 0 || (!isOperand(eq[i - 1]) && eq[i - 1] != ')'))) {
            while (!isEmpty(S) && 6 <= priority(top(S)))
                print(pop(S));
            if (s == '+')
                push(S, 'p');
            else
                push(S, 'm');
        } else {
            while (!isEmpty(S) && priority(s) <= priority(top(S)))
                print(pop(S));
            push(S, s);
            if (s == '|' || s == '&')
                i++;
        }
    }
    while (!isEmpty(S))
        print(pop(S));
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    char eq[101];
    for (int i = 0; i < N; i++) {
        scanf("%s", eq);
        convert(eq);
    }

    return (0);
}