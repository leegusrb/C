#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char elems[1000];
	int top;
	int cnt;
	int chk;
} Stack;

void initStack(Stack *S) {
	S->top = -1;
	S->cnt = 0;
	S->chk = 1;
}

int isEmpty(Stack *S) {
	return (S->top == -1);
}

void push(Stack *S, char e) {
	S->top++;
	S->elems[S->top] = e;
}

char pop(Stack *S) {
	if (isEmpty(S))
		return (0);

	S->top--;
	return (S->elems[S->top + 1]);
}

char peek(Stack *S) {
	if (isEmpty(S))
		return (0);

	return (S->elems[S->top]);
}

void check(Stack *S, char *eq) {
	for (int i = 0; eq[i]; i++) {
		if (eq[i] == '{' || eq[i] == '[' || eq[i] == '(') {
			push(S, eq[i]);
			S->cnt++;
		} else if (eq[i] == '}' || eq[i] == ']' || eq[i] == ')') {
			char tmp = pop(S);
			if ((eq[i] == '}' && tmp != '{') || (eq[i] == ']' && tmp != '[') || (eq[i] == ')' && tmp != '('))
				S->chk = 0;
			S->cnt++;
		}
	}

	if (!isEmpty(S))
		S->chk = 0;
}

int main() {
	Stack *S = (Stack *) malloc(sizeof(Stack));
	initStack(S);

	char eq[1000];
	gets(eq);

	check(S, eq);

	if (S->chk)
		printf("OK_%d\n", S->cnt);
	else
		printf("Wrong_%d\n", S->cnt);
}