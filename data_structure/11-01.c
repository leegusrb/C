#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *elems;
	int front;
	int rear;
	int size;
} Queue;

void initQueue(Queue *Q) {
	scanf("%d", &Q->size);

	Q->elems = (int *) malloc(sizeof(int) * Q->size);
	for (int i = 0; i < Q->size; i++)
		Q->elems[i] = 0;
	Q->front = 0;
	Q->rear = 0;
}

int isFull(Queue *Q) {
	return ((Q->rear + 1) % Q->size == Q->front);
}

int isEmpty(Queue *Q) {
	return (Q->rear == Q->front);
}

int nextIdx(Queue *Q, int n) {
	return (++n % Q->size);
}

void print(Queue *Q) {
	for (int i = 0; i < Q->size; i++)
		printf(" %d", Q->elems[i]);
	printf("\n");
}

int enqueue(Queue *Q, int e) {
	if (isFull(Q)) {
		printf("overflow");
		print(Q);
		return (0);
	}

	Q->rear = nextIdx(Q, Q->rear);
	Q->elems[Q->rear] = e;
	return (1);
}

int dequeue(Queue *Q) {
	if (isEmpty(Q)) {
		printf("underflow\n");
		return (0);
	}

	Q->front = nextIdx(Q, Q->front);
	int e = Q->elems[Q->front];
	Q->elems[Q->front] = 0;
	return (e);
}

int main() {
	Queue *Q = (Queue *) malloc(sizeof(Queue));
	initQueue(Q);

	int n, e;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'I') {
			scanf("%d", &e);
			if (!enqueue(Q, e))
				break;
		} else if (c == 'D') {
			if (!dequeue(Q))
				break;
		} else if (c == 'P') {
			print(Q);
		}
	}

	return (0);
}