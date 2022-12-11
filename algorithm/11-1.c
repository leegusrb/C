#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct incidentEdge {
    int aName;
    struct incidentEdge *next;
} incidentEdge;

typedef struct vertex {
    int vName;
    int isVisit;
    incidentEdge *iHead;
    struct vertex *next;
} vertex;

typedef struct {
    vertex *vHead;
} graph;

void initGraph(graph *G);

void initVertex(vertex *V, int vName);

void initIncidentEdge(incidentEdge *I, int aName);

void makeVertex(graph *G, int vName);

void insertEdge(graph *G, int v1, int v2);

void makeIncidentEdge(vertex *v, int aName);

vertex *findVertex(graph *G, int vName);

void print(graph *G);

void DFS(graph *G, int vName);

int main() {
    graph *G = (graph *) malloc(sizeof(graph));
    initGraph(G);

    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    for (int i = 1; i <= n; i++) {
        makeVertex(G, i);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        insertEdge(G, v1, v2);
    }

    DFS(G, s);

    return 0;
}

void initGraph(graph *G) {
    G->vHead = NULL;
}

void initVertex(vertex *V, int vName){
    V->vName = vName;
    V->isVisit = FALSE;
    V->iHead = NULL;
    V->next = NULL;
}

void initIncidentEdge(incidentEdge *I, int aName){
    I->aName = aName;
    I->next = NULL;
}

void makeVertex(graph *G, int vName){
    vertex *v = (vertex *) malloc(sizeof(vertex));
    initVertex(v, vName);

    vertex *p = G->vHead;
    if (p == NULL) {
        G->vHead = v;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = v;
    }
}

void insertEdge(graph *G, int v1, int v2){
    vertex *v = findVertex(G, v1);
    makeIncidentEdge(v, v2);
    v = findVertex(G, v2);
    makeIncidentEdge(v, v1);
}

void makeIncidentEdge(vertex *v, int aName){
    incidentEdge *i = (incidentEdge *) malloc(sizeof(incidentEdge));
    initIncidentEdge(i, aName);

    incidentEdge *q = v->iHead;
    if (q == NULL) {
        v->iHead = i;
    } else if (i->aName < q->aName) {
        i->next = q;
        v->iHead = i;
    } else {
        while (q->next && i->aName > q->next->aName) {
            q = q->next;
        }
        i->next = q->next;
        q->next = i;
    }
}

vertex *findVertex(graph *G, int vName){
    vertex *p = G->vHead;

    while (p && p->vName != vName) {
        p = p->next;
    }

    return p;
}

void print(graph *G){
    for (vertex *p = G->vHead; p; p = p->next) {
        printf("[%d] : ", p->vName);
        for (incidentEdge *i = p->iHead; i; i = i->next) {
            printf("[%d] ", i->aName);
        }
        printf("\n");
    }
}

void DFS(graph *G, int vName){
    vertex *v = findVertex(G, vName);

    if (v->isVisit == FALSE) {
        v->isVisit = TRUE;
        printf("%d\n", v->vName);
    }

    for (incidentEdge *q = v->iHead; q; q = q->next) {
        v = findVertex(G, q->aName);
        if (v->isVisit == FALSE) {
            DFS(G, v->vName);
        }
    }
}