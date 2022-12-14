#include <stdio.h>
#include <stdlib.h>

#define INF (30 * 1000)

typedef struct Edge {
    int from, to;
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

void insertVertex(Graph *G, int vName);

void insertEdge(Graph *G, int from, int to, int weight);

Vertex *findVertex(Graph *G, int vName);

void BellmanFordShortestPaths(Graph *G);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    scanf("%d %d %d", &n, &m, &s);

    for (int i = 1; i <= n; i++) {
        insertVertex(G, i);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        insertEdge(G, v1, v2, weight);
    }

    BellmanFordShortestPaths(G);

    return 0;
}


void initGraph(Graph *G) {
    G->vHead = NULL;
    G->eHead = NULL;
}

void insertVertex(Graph *G, int vName) {
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

void insertEdge(Graph *G, int from, int to, int weight) {
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->from = from;
    e->to = to;
    e->weight = weight;
    e->next = NULL;

    Edge *p = G->eHead;
    if (p == NULL) {
        G->eHead = e;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = e;
    }

}

Vertex *findVertex(Graph *G, int vName) {
    Vertex *v = G->vHead;

    while (v && v->vName != vName) {
        v = v->next;
    }

    return v;
}

void BellmanFordShortestPaths(Graph *G) {
    findVertex(G, s)->d = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge *p = G->eHead; p; p = p->next) {
            Vertex *v = findVertex(G, p->from);
            Vertex *w = findVertex(G, p->to);

            if (w->d == INF && v->d == INF) continue;

            if (w->d > v->d + p->weight) {
                w->d = v->d + p->weight;
            }
        }
    }

    for (Vertex *p = G->vHead; p; p = p->next) {
        if (p->vName != s && p->d != INF) {
            printf("%d %d\n", p->vName, p->d);
        }
    }
}