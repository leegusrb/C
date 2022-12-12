#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF 1000

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
    IncidentEdge *iHead;
    int d;
    Edge *p;
    int isVisit;
    struct Vertex *next;
} Vertex;

typedef struct {
    Vertex *vHead;
    Edge *eHead;
} Graph;

int n, m;

void initGraph(Graph *G);

void makeVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2, int weight);

void insertIncidentEdge(Vertex *v, Edge *e);

Vertex *findVertex(Graph *G, int vName);

void PrimJarnikMST(Graph *G);

Vertex *findMinVertex(Graph *G);

int opposite(Vertex *v, IncidentEdge *i);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        makeVertex(G, i);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        insertEdge(G, v1, v2, w);
    }

    PrimJarnikMST(G);

    return 0;
}

void initGraph(Graph *G){
    G->vHead = NULL;
}

void makeVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->iHead = NULL;
    v->d = INF;
    v->p = NULL;
    v->isVisit = FALSE;
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
    insertIncidentEdge(p,  e);
}

void insertIncidentEdge(Vertex *v, Edge *e){
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

Vertex *findVertex(Graph *G, int vName){
    Vertex *p = G->vHead;

    while (p && p->vName != vName) {
        p = p->next;
    }

    return p;
}

void PrimJarnikMST(Graph *G){
    Vertex *s = findVertex(G, 1);
    s->d = 0;

    int tot = 0;

    for (int i = 0; i < n; i++) {
        Vertex *u = findMinVertex(G);
        u->isVisit = TRUE;
        printf(" %d", u->vName);
        tot += u->d;
        IncidentEdge *p = u->iHead;
        while (p) {
            Vertex *z = findVertex(G, opposite(u, p));
            if (z->isVisit == FALSE && p->e->weight < z->d) {
                z->d = p->e->weight;
                z->p = p->e;
            }

            p = p->next;
        }
    }

    printf("\n%d\n", tot);
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

    while (p) {
        if (p->isVisit == FALSE && p->d < min->d) {
            min = p;
        }
        p = p->next;
    }

    return min;
}

int opposite(Vertex *v, IncidentEdge *i) {
    Edge *e = i->e;

    if (e->v1 == v->vName) {
        return e->v2;
    } else {
        return e->v1;
    }
}