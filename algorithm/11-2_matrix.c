#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int n;

typedef struct {
    int **mat;
    int *isVisit;
} graph;

typedef struct {
    int elem[100];
    int front, rear;
} queue;

void initGraph(graph *G);

void insertEdge(graph *G, int v1, int v2);

void initQueue(queue *Q);

int isQueueEmpty(queue *Q);

void enqueue(queue *Q, int v);

int dequeue(queue *Q);

void BFS(graph *G, int vName);

int main() {
    graph *G = (graph *) malloc(sizeof(graph));

    int m, s;
    scanf("%d %d %d", &n, &m, &s);

    initGraph(G);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        insertEdge(G, v1, v2);
    }

    BFS(G, s);

    return 0;
}

void initGraph(graph *G) {
    G->mat = (int **) malloc(sizeof(int *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        G->mat[i] = (int *) malloc(sizeof(int) * (n + 1));
        for (int j = 1; j <= n; j++) {
            G->mat[i][j] = 0;
        }
    }
    G->isVisit = (int *) malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        G->isVisit[i] = FALSE;
    }
}

void insertEdge(graph *G, int v1, int v2) {
    G->mat[v1][v2] = 1;
    G->mat[v2][v1] = 1;
}

void initQueue(queue *Q) {
    Q->front = Q->rear = 0;
}

int isQueueEmpty(queue *Q) {
    return Q->front == Q->rear;
}

void enqueue(queue *Q, int v) {
    Q->rear = (Q->rear + 1) % 100;
    Q->elem[Q->rear] = v;
}

int dequeue(queue *Q) {
    Q->front = (Q->front + 1) % 100;
    return Q->elem[Q->front];
}

void BFS(graph *G, int vName) {
    queue *Q = (queue *) malloc(sizeof(queue));
    initQueue(Q);

    G->isVisit[vName] = TRUE;
    printf("%d\n", vName);
    enqueue(Q, vName);

    while (!isQueueEmpty(Q)) {
        int v = dequeue(Q);
        for (int i = 1; i <= n; i++) {
            if (G->mat[v][i] != 0 && G->isVisit[i] == FALSE) {
                G->isVisit[i] = TRUE;
                printf("%d\n", i);
                enqueue(Q, i);
            }
        }
    }
}