#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *elems;
	int size;
	int top;
} Stack;

void initStack(Stack *S, int N) {
	S->elems = (char *) malloc(sizeof(char) * N);
	S->size = N;
	S->top = -1;
}

int isFull(Stack *S) {
	return (S->top == S->size - 1);
}

int isEmpty(Stack *S) {
	return (S->top == -1);
}

void push(Stack *S, char e) {
	if (isFull(S)) {
		printf("Stack FULL\n");
		return;
	}

	S->top++;
	S->elems[S->top] = e;
}

char pop(Stack *S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return (0);
	}

	S->top--;
	return (S->elems[S->top + 1]);
}

char peek(Stack *S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return (0);
	}

	return (S->elems[S->top]);
}

void duplicate(Stack *S) {
	if (isFull(S)) {
		printf("Stack FULL\n");
		return;
	}

	char e = pop(S);
	push(S, e);
	push(S, e);
}

void upRotate(Stack *S, int n) {
	if (n > S->top + 1)
		return;

	char tmp = S->elems[S->top];
	for (int i = S->top; i > S->top - n + 1; i--)
		S->elems[i] = S->elems[i - 1];
	S->elems[S->top - n + 1] = tmp;
}

void downRotate(Stack *S, int n) {
	if (n > S->top + 1)
		return;

	char tmp = S->elems[S->top - n + 1];
	for (int i = S->top - n + 1; i < S->top; i++) 
		S->elems[i] = S->elems[i + 1];
	S->elems[S->top] = tmp;
}

void print(Stack *S) {
	for (int i = S->top; i >= 0; i--)
		printf("%c", S->elems[i]);
	printf("\n");
}

int main() {
	int N;
	Stack *S;

	scanf("%d", &N);
	S = (Stack *) malloc(sizeof(Stack));
	initStack(S, N);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char s[6], e;
		int n;

		getchar();
		scanf("%s", s);
		if (!strcmp(s, "PUSH")) {
			getchar();
			scanf("%c", &e);
			push(S, e);
		} else if (!strcmp(s, "POP")) {
			e = pop(S);
		} else if (!strcmp(s, "PEEK")) {
			e = peek(S);
			if (e)
				printf("%c\n", e);
		} else if (!strcmp(s, "DUP")) {
			duplicate(S);
		} else if (!strcmp(s, "UpR")) {
			scanf("%d", &n);
			upRotate(S, n);
		} else if (!strcmp(s, "DownR")) {
			scanf("%d", &n);
			downRotate(S, n);
		} else if (!strcmp(s, "PRINT")) {
			print(S);
		}
	}
}