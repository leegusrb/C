#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct IncidentEdge {
    char to;
    struct IncidentEdge *next;
} IncidentEdge;

typedef struct Vertex {
    char vName;
    int inDegree;
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

int n, m;

void initGraph(Graph *G);

void insertVertex(Graph *G, char vName);

void insertEdge(Graph *G, char from, char to);

void insertIncidentEdge(Vertex *v, char to);

Vertex *findVertex(Graph *G, char vName);

void initQueue(Queue *Q);

void enqueue(Queue *Q, Vertex *v);

Vertex *dequeue(Queue *Q);

int isEmpty(Queue *Q);

void topologicalSort(Graph *G);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char vName;
        getchar();
        scanf("%c", &vName);
        insertVertex(G, vName);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char from, to;
        getchar();
        scanf("%c %c", &from, &to);
        insertEdge(G, from, to);
    }

    topologicalSort(G);

    return 0;
}


void initGraph(Graph *G) {
    G->vHead = NULL;
}

void insertVertex(Graph *G, char vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->inDegree = 0;
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

void insertEdge(Graph *G, char from, char to) {
    insertIncidentEdge(findVertex(G, from), to);
    findVertex(G, to)->inDegree++;
}

void insertIncidentEdge(Vertex *v, char to) {
    IncidentEdge *i = (IncidentEdge *) malloc(sizeof(IncidentEdge));
    i->to = to;
    i->next = NULL;

    IncidentEdge *p = v->iHead;
    if (p == NULL) {
        v->iHead = i;
    } else {
        i->next = p;
        v->iHead = i;
    }
}

Vertex *findVertex(Graph *G, char vName) {
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

void topologicalSort(Graph *G){
    Queue *Q = (Queue *) malloc(sizeof(Queue));
    initQueue(Q);

    for (Vertex *p = G->vHead; p; p = p->next) {
        if (p->inDegree == 0) {
            enqueue(Q, p);
            p->isVisit = TRUE;
        }
    }

    Vertex **topOrder = (Vertex **) malloc(sizeof(Vertex *) * (n));
    int t = 0;
    
    while (!isEmpty(Q)) {
        Vertex *v = dequeue(Q);
        topOrder[t++] = v;
        for (IncidentEdge *p = v->iHead; p; p = p->next) {
            Vertex *w = findVertex(G, p->to);
            if (w->isVisit == FALSE) {
                w->inDegree--;
                if (w->inDegree == 0) {
                    enqueue(Q, w);
                    w->isVisit = TRUE;
                }
            }
        }
    }

    if (t < n) {
        printf("0\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%c ", topOrder[i]->vName);
        }
        printf("\n");
    }
}