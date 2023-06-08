#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int id, data;
	struct Node *left, *right;
} Node;

Node *makeNode(int id, int data, Node *left, Node *right) {
	Node *node = (Node *) malloc(sizeof(Node));

	node->id = id;
	node->data = data;
	node->left = left;
	node->right = right;

	return (node);
}

Node *findNode(Node *root, int id) {
	if (!root)
		return (NULL);

	if (root->id == id)
		return (root);

	Node *p = findNode(root->left, id);
	if (!p)
		p = findNode(root->right, id);

	return (p);
}

void preOrder(Node *root) {
	if (!root) return;

	printf(" %d", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root) {
	if (!root) return;

	inOrder(root->left);
	printf(" %d", root->data);
	inOrder(root->right);
}

void postOrder(Node *root) {
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	printf(" %d", root->data);
}

int main() {
	Node *F8 = makeNode(8, 80, NULL, NULL);
	Node *F7 = makeNode(7, 130, NULL, NULL);
	Node *F6 = makeNode(6, 120, F7, F8);
	Node *F5 = makeNode(5, 90, NULL, NULL);
	Node *F4 = makeNode(4, 70, NULL, NULL);
	Node *F3 = makeNode(3, 50, NULL, F6);
	Node *F2 = makeNode(2, 30, F4, F5);
	Node *F1 = makeNode(1, 20, F2, F3);

	int order, id;
	scanf("%d %d", &order, &id);

	Node *p = findNode(F1, id);

	if (!p)
		printf("-1");
	else if (order == 1)
		preOrder(p);
	else if (order == 2)
		inOrder(p);
	else if (order == 3)
		postOrder(p);
	printf("\n");

	return (0);
}