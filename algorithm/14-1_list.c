#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF (30 * 1000)

typedef struct Edge {
    int weight;
    struct Edge *next;
} Edge;

typedef struct IncidentEdge {
    int aName;
    Edge *e;
    struct IncidentEdge *next;
} IncidentEdge;

typedef struct Vertex {
    int vName;
    int isVisit;
    int d;
    IncidentEdge *iHead;
    struct Vertex *next;
} Vertex;

typedef struct {
    Vertex *vHead;
    Edge *eHead;
} Graph;

int n, m, s;

void initGraph(Graph *G);

void insertVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2, int weight);

void insertIncidentEdge(Vertex *v, int aName, Edge *e);

Vertex *findVertex(Graph *G, int vName);

void DijkstraShortestPaths(Graph *G);

Vertex *findMin(Graph *G);

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

    DijkstraShortestPaths(G);

    return 0;
}


void initGraph(Graph *G) {
    G->vHead = NULL;
    G->eHead = NULL;
}

void insertVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->d = INF;
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

    insertIncidentEdge(findVertex(G, v1), v2, e);
    insertIncidentEdge(findVertex(G, v2), v1, e);
}

void insertIncidentEdge(Vertex *v, int aName, Edge *e) {
    IncidentEdge *i = (IncidentEdge *) malloc(sizeof(IncidentEdge));
    i->aName = aName;
    i->e = e;
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

void DijkstraShortestPaths(Graph *G) {
    findVertex(G, s)->d = 0;

    for (int i = 0; i < n; i++) {
        Vertex *v = findMin(G);
        v->isVisit = TRUE;
        for (IncidentEdge *p = v->iHead; p; p = p->next) {
            Vertex *w = findVertex(G, p->aName);
            if (w->isVisit == FALSE &&  w->d > v->d + p->e->weight) {
                w->d = v->d + p->e->weight;
            }
        }
    }
    
    for (Vertex *p = G->vHead; p; p = p->next) {
        if (p->vName != s && p->d != INF) {
            printf("%d %d\n", p->vName, p->d);
        }
    }
}

Vertex *findMin(Graph *G) {
    Vertex *min = NULL;
    
    for (Vertex *p = G->vHead; p; p = p->next) {
        if (p->isVisit == FALSE) {
            min = p;
            break;
        }
    }
    
    for (Vertex *p = min; p; p = p->next) {
        if (p->isVisit == FALSE && p->d < min->d) {
            min = p;
        }
    }
    
    return min;
}