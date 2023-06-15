#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char elem;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
	int maxSize;
} Stack;

int countSize(Stack *S) {
	Node *p = S->top;
	int cnt = 0;

	while (p) {
		cnt++;
		p = p->next;
	}

	return (cnt);
}

int isEmpty(Stack *S) {
	return (S->top == NULL);
}

int isFull(Stack *S) {
	return (countSize(S) == S->maxSize);
}

Node *makeNode(char e) {
	Node *p = (Node *) malloc(sizeof(Node));
	p->elem = e;
	p->next = NULL;
	return (p);
}

void initStack(Stack *S) {
	S->top = NULL;
	scanf("%d", &S->maxSize);
}

void push(Stack *S, char e) {
	if (isFull(S)) {
		printf("Stack FULL\n");
		return ;
	}

	Node *p = makeNode(e);
	p->next = S->top;
	S->top = p;
}

char pop(Stack *S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return (0);
	}

	char e = S->top->elem;
	Node *p = S->top;
	S->top = S->top->next;
	free(p);
	return (e);
}

char peek(Stack *S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return (0);
	}

	return (S->top->elem);
}

void duplicate(Stack *S) {
	char e = pop(S);
	push(S, e);
	push(S, e);
}

void upRotate(Stack *S, int n) {
	if (countSize(S) < n)
		return ;

	Node *rot = S->top;
	Node *p = S->top;
	S->top = S->top->next;

	for (int i = 0; i < n - 1; i++)
		p = p->next;
	rot->next = p->next;
	p->next = rot;
}

void downRotate(Stack *S, int n) {
	if (countSize(S) < n)
		return ;

	Node *p = S->top;

	for (int i = 0; i < n - 2; i++)
		p = p->next;
	Node *rot = p->next;

	p->next = rot->next;
	rot->next = S->top;
	S->top = rot;
}

void print(Stack *S) {
	Node *p = S->top;
	while (p) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main() {
	Stack *S = (Stack *) malloc(sizeof(Stack));
	initStack(S);

	int n, rot;
	char str[6], e;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", str);
		if (strcmp(str, "PUSH") == 0) {
			getchar();
			scanf("%c", &e);
			push(S, e);
		} else if (strcmp(str, "POP") == 0) {
			e = pop(S);
		} else if (strcmp(str, "PEEK") == 0) {
			e = peek(S);
			if (e)
				printf("%c\n", e);
		} else if (strcmp(str, "DUP") == 0) {
			duplicate(S);
		} else if (strcmp(str, "UpR") == 0) {
			scanf("%d", &rot);
			upRotate(S, rot);
		} else if (strcmp(str, "DownR") == 0) {
			scanf("%d", &rot);
			downRotate(S, rot);
		} else if (strcmp(str, "PRINT") == 0) {
			print(S);
		}
	}

	return (0);
}