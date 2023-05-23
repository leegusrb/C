#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node *makeNode(int data, Node *left, Node *right) {
	Node *p = (Node *) malloc(sizeof(Node));

	p->data = data;
	p->left = left;
	p->right = right;

	return (p);
}

void print(Node *p) {
	printf("%d ", p->data);
	if (p->left)
		printf("%d ", p->left->data);
	if (p->right)
		printf("%d ", p->right->data);
	printf("\n");
}

int main() {
	Node *F8 = makeNode(80, NULL, NULL);
	Node *F7 = makeNode(130, NULL, NULL);
	Node *F6 = makeNode(120, F7, F8);
	Node *F5 = makeNode(90, NULL, NULL);
	Node *F4 = makeNode(70, NULL, NULL);
	Node *F3 = makeNode(50, NULL, F6);
	Node *F2 = makeNode(30, F4, F5);
	Node *F1 = makeNode(20, F2, F3);

	int n;
	scanf("%d", &n);

	if (n == 1)
		print(F1);
	else if (n == 2)
		print(F2);
	else if (n == 3)
		print(F3);
	else if (n == 4)
		print(F4);
	else if (n == 5)
		print(F5);
	else if (n == 6)
		print(F6);
	else if (n == 7)
		print(F7);
	else if (n == 8)
		print(F8);
	else
		printf("-1\n");

	return (0);
}