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

int n, m;

void initGraph(Graph *G);

void insertVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2, int weight);

void insertIncidentEdge(Vertex *v, int aName, Edge *e);

Vertex *findVertex(Graph *G, int vName);

void PrimJarnikMST(Graph *G);

Vertex *findMin(Graph *G);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        insertVertex(G, i);
    }
    
    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        insertEdge(G, v1, v2, weight);
    }

    PrimJarnikMST(G);

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
    e->v1 = v1;
    e->v2 = v2;
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

void PrimJarnikMST(Graph *G) {
    findVertex(G, 1)->d = 0;
    
    int tot = 0;
    int cnt = 0;
    while (cnt < n) {
        Vertex *v = findMin(G);
        printf(" %d", v->vName);
        v->isVisit = TRUE;
        tot += v->d;
        cnt++;

        for (IncidentEdge *p = v->iHead; p; p = p->next) {
            Vertex *w = findVertex(G, p->aName);
            if (w->isVisit == FALSE && p->e->weight < w->d) {
                w->d = p->e->weight;
            }
        }
    }
    printf("\n");

    printf("%d\n", tot);
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