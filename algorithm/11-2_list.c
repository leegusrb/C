#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct IncidentEdge {
    int aName;
    struct IncidentEdge *next;
} IncidentEdge;

typedef struct Vertex {
    int vName;
    int isVisit;
    IncidentEdge *iHead;
    struct Vertex *next;
} Vertex;

typedef struct {
    Vertex *vHead;
} Graph;

typedef struct {
    Vertex **e;
    int front, rear;
} Queue;

int n, m, s;

void initGraph(Graph *G);

void insertVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2);

void insertIncidentEdge(Vertex *v, int aName);

Vertex *findVertex(Graph *G, int vName);

void initQueue(Queue *Q);

void enqueue(Queue *Q, Vertex *v);

Vertex *dequeue(Queue *Q);

int isEmpty(Queue *Q);

void BFS(Graph *G);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    scanf("%d %d %d", &n, &m, &s);

    for (int i = 1; i <= n; i++) {
        insertVertex(G, i);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        insertEdge(G, v1, v2);
    }

    BFS(G);

    return 0;
}


void initGraph(Graph *G) {
    G->vHead = NULL;
}

void insertVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;

    Vertex *p = G->vHead;
    if (p == NULL) {
        G->vHead = v;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = v;
    }
}

void insertEdge(Graph *G, int v1, int v2) {
    insertIncidentEdge(findVertex(G, v1), v2);
    insertIncidentEdge(findVertex(G, v2), v1);
}

void insertIncidentEdge(Vertex *v, int aName) {
    IncidentEdge *i = (IncidentEdge *) malloc(sizeof(IncidentEdge));
    i->aName = aName;
    i->next = NULL;

    IncidentEdge *p = v->iHead;
    if (p == NULL) {
        v->iHead = i;
    } else {
        if (p->aName > i->aName) {
            i->next = p;
            v->iHead = i;
        } else {
            while (p->next && p->next->aName < i->aName) {
                p = p->next;
            }
            i->next = p->next;
            p->next = i;
        }
    }
}

Vertex *findVertex(Graph *G, int vName) {
    Vertex *v = G->vHead;

    while (v && v->vName != vName) {
        v = v->next;
    }

    return v;
}

void initQueue(Queue *Q){
    Q->e = (Vertex **) malloc(sizeof(Vertex *) * n);
    Q->front = 0;
    Q->rear = 0;
}

void enqueue(Queue *Q, Vertex *v){
    Q->rear = (Q->rear + 1) % n;
    Q->e[Q->rear] = v;
}

Vertex *dequeue(Queue *Q){
    Q->front = (Q->front + 1) % n;
    return Q->e[Q->front];
}

int isEmpty(Queue *Q){
    return Q->front == Q->rear;
}

void BFS(Graph *G) {
    Queue *Q = (Queue *) malloc(sizeof(Queue));
    initQueue(Q);

    Vertex *v = findVertex(G, s);
    v->isVisit = TRUE;
    printf("%d\n", v->vName);
    enqueue(Q, v);

    while (!isEmpty(Q)) {
        v = dequeue(Q);
        for (IncidentEdge *p = v->iHead; p; p = p->next) {
            Vertex *w = findVertex(G, p->aName);
            if (w->isVisit == FALSE) {
                w->isVisit = TRUE;
                printf("%d\n", w->vName);
                enqueue(Q, w);
            }
        }
    }
}