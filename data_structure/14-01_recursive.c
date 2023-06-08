#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node *makeNode(int data) {
	Node *p = (Node *) malloc(sizeof(Node));
	p->data = data;
	p->left = p->right = NULL;
	return (p);
}

void connectNode(Node *p, int l, int r) {
	int data, left, right;
	
	if (l != 0) {
		p->left = makeNode(l);
		scanf("%d %d %d", &data, &left, &right);
		connectNode(p->left, left, right);
	}
	
	if (r != 0) {
		p->right = makeNode(r);
		scanf("%d %d %d", &data, &left, &right);
		connectNode(p->right, left, right);
	}
}

Node *makeTree() {
	int n, d, l ,r;
	scanf("%d", &n);

	scanf("%d %d %d", &d, &l, &r);
	Node *root = makeNode(d);
	connectNode(root, l, r);

	return (root);
}

void search(Node *p, char *str) {
	printf(" %d", p->data);
	if (*str == 'L')
		search(p->left, str + 1);
	else if (*str == 'R')
		search(p->right, str + 1);
}

int main() {
	Node *root = makeTree();

	int s;
	char str[101];

	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%s", str);
		search(root, str);
	}

	return (0);
}