#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int elem;
	struct Node *prev, *next;
} Node;

typedef struct {
	Node *front, *rear;
} Deque;

void initDeque(Deque *D) {
	D->front = D->rear = NULL;
}

void addFront(Deque *D, int e) {
	Node *p = (Node *) malloc(sizeof(Node));

	p->elem = e;
	p->prev = NULL;
	p->next = D->front;

	if (!D->front) {
		D->front = D->rear = p;
	} else {
		D->front->prev = p;
		D->front = p;
	}
}

void addRear(Deque *D, int e) {
	Node *p = (Node *) malloc(sizeof(Node));

	p->elem = e;
	p->prev = D->rear;
	p->next = NULL;

	if (!D->rear) {
		D->front = D->rear = p;
	} else {
		D->rear->next = p;
		D->rear = p;
	}
}

int deleteFront(Deque *D) {
	if (!D->front) {
		printf("underflow\n");
		return (0);
	}
	int e = D->front->elem;

	if (!D->front->next) {
		free(D->front);

		D->front = D->rear = NULL;
	} else {
		Node *p = D->front->next;

		free(D->front);
		p->prev = NULL;
		D->front = p;
	}

	return (e);
}

int deleteRear(Deque *D) {
	if (!D->rear) {
		printf("underflow\n");
		return (0);
	}
	int e = D->rear->elem;

	if (!D->rear->prev) {
		free(D->rear);

		D->front = D->rear = NULL;
	} else {
		Node *p = D->rear->prev;

		free(D->rear);
		p->next = NULL;
		D->rear = p;
	}

	return (e);
}

void print(Deque *D) {
	for (Node *p = D->front; p; p = p->next)
		printf(" %d", p->elem);
	printf("\n");
}

int main() {
	Deque *D = (Deque *) malloc(sizeof(Deque));
	initDeque(D);

	int n, e;
	char st[3];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", st);
		if (strcmp(st, "AF") == 0) {
			scanf("%d", &e);
			addFront(D, e);
		} else if (strcmp(st, "AR") == 0) {
			scanf("%d", &e);
			addRear(D, e);
		} else if (strcmp(st, "DF") == 0) {
			if (!deleteFront(D)) break;
		} else if (strcmp(st, "DR") == 0) {
			if (!deleteRear(D)) break;
		} else if (strcmp(st, "P") == 0) {
			print(D);
		}
	}

	return (0);
}