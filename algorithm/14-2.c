
#include <stdio.h>
#include <stdlib.h>

#define INF (30 * 1000)

typedef struct Edge {
    int v1, v2;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    int vName;
    int d;
    struct Vertex *next;
} Vertex;

typedef struct {
    Vertex *vHead;
    Edge *eHead;
} Graph;

int n, m, s;

void initGraph(Graph *G);

void makeVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2, int weight);

Vertex *findVertex(Graph *G, int vName);

void BellmanFordShortestPaths(Graph *G);

int min(int a, int b);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    scanf("%d %d %d", &n, &m, &s);

    for (int i = 1; i <= n; i++) {
        makeVertex(G, i);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        insertEdge(G, v1, v2, w);
    }

    BellmanFordShortestPaths(G);

    return 0;
}

void initGraph(Graph *G) {
    G->vHead = NULL;
}

void makeVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->d = INF;
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

void insertEdge(Graph *G, int v1, int v2, int weight) {
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->v1 = v1;
    e->v2 = v2;
    e->weight = weight;
    e->next = NULL;

    Edge *q = G->eHead;
    if (q == NULL) {
        G->eHead = e;
    } else {
        while (q->next) {
            q = q->next;
        }
        q->next = e;
    }
}

Vertex *findVertex(Graph *G, int vName) {
    Vertex *p = G->vHead;

    while (p && p->vName != vName) {
        p = p->next;
    }

    return p;
}

void BellmanFordShortestPaths(Graph *G){
    findVertex(G, s)->d = 0;

    for (int i = 1; i < n; i++) {
        for (Edge *q = G->eHead; q; q = q->next) {
            Vertex *u = findVertex(G, q->v1);
            Vertex *z = findVertex(G, q->v2);
            if (z->d == INF && u->d == INF) continue;
            z->d = min(z->d, u->d + q->weight);
        }
    }

    for (Vertex *p = G->vHead; p; p = p->next) {
        if (s != p->vName && p->d != INF) {
            printf("%d %d\n", p->vName, p->d);
        }
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}