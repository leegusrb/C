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

Node *findNode(Node *p, int d) {
	if (!p || p->data == d)
		return (p);

	Node *tmp = findNode(p->left, d);
	if (tmp)
		return (tmp);

	return (findNode(p->right, d));
}

void connectNode(Node *root, int d, int l, int r) {
	Node *p = findNode(root, d);

	if (l != 0)
		p->left = makeNode(l);
	if (r != 0)
		p->right = makeNode(r);
}

Node *makeTree() {
	int n, d, l ,r;
	scanf("%d", &n);

	scanf("%d %d %d", &d, &l, &r);
	Node *root = makeNode(d);
	connectNode(root, d, l, r);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &d, &l, &r);
		connectNode(root, d, l, r);
	}

	return (root);
}

void search(Node *root, char *str) {
	Node *p = root;
	printf(" %d", p->data);
	for(int i = 0; str[i]; i++) {
		if (str[i] == 'L')
			p = p->left;
		else
			p = p->right;
		printf(" %d", p->data);
	}
	printf("\n");
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