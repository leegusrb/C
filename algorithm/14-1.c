#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF (30 * 1000)

typedef struct Edge {
    int v1, v2;
    int weight;
    struct Edge *next;
} Edge;

typedef struct IncidentEdge {
    Edge *e;
    struct IncidentEdge *next;
} IncidentEdge;

typedef struct Vertex {
    int vName;
    int d;
    int isVisit;
    IncidentEdge *iHead;
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

void insertIncidentEdge(Vertex *v, Edge *e);

Vertex *findVertex(Graph *G, int vName);

void DijkstraShortestPaths(Graph *G);

Vertex *findMinVertex(Graph *G);

int opposite(Vertex *v, IncidentEdge *i);

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

    DijkstraShortestPaths(G);

    return 0;
}

void initGraph(Graph *G) {
    G->vHead = NULL;
}

void makeVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->d = INF;
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

    Vertex *p = findVertex(G, v1);
    insertIncidentEdge(p, e);
    p = findVertex(G, v2);
    insertIncidentEdge(p, e);
}

void insertIncidentEdge(Vertex *v, Edge *e) {
    IncidentEdge *i = (IncidentEdge *) malloc(sizeof(IncidentEdge));
    i->e = e;
    i->next = NULL;

    IncidentEdge *p = v->iHead;
    if (p == NULL) {
        v->iHead = i;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = i;
    }
}

Vertex *findVertex(Graph *G, int vName) {
    Vertex *p = G->vHead;

    while (p && p->vName != vName) {
        p = p->next;
    }

    return p;
}

void DijkstraShortestPaths(Graph *G) {
    findVertex(G, s)->d = 0;

    for (int i = 0; i < n; i++) {
        Vertex *u = findMinVertex(G);
        u->isVisit = TRUE;
        IncidentEdge *ie = u->iHead;
        while (ie) {
            Vertex *z = findVertex(G, opposite(u, ie));
            if (z->isVisit == FALSE) {
                if (u->d + ie->e->weight < z->d) {
                    z->d = u->d + ie->e->weight;
                }
            }

            ie = ie->next;
        }
    }

    Vertex *p = G->vHead;
    for (int i = 0; i < n; i++) {
        if (p->vName != s && p->d != INF) {
            printf("%d %d\n", p->vName, p->d);
        }
        p = p->next;
    }
}

Vertex *findMinVertex(Graph *G){
    Vertex *p = G->vHead;
    Vertex *min = NULL;
    
    while (p) {
        if (p->isVisit == FALSE) {
            min = p;
            break;
        }
        p = p->next;
    }
    
    p = min;
    
    while(p) {
        if (p->isVisit == FALSE && p->d < min->d) {
            min = p;
        }
        p = p->next;
    }
    
    return min;
}

int opposite(Vertex *v, IncidentEdge *i){
    if (i->e->v1 == v->vName) {
        return i->e->v2;
    } else {
        return i->e->v1;
    }
}