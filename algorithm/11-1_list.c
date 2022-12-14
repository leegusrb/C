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

void initGraph(Graph *G);

void insertVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2);

void insertIncidentEdge(Vertex *v, int aName);

Vertex *findVertex(Graph *G, int vName);

void DFS(Graph *G, int s);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    for (int i = 1; i <= n; i++) {
        insertVertex(G, i);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        insertEdge(G, v1, v2);
    }

    DFS(G, s);

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

void DFS(Graph *G, int s) {
    Vertex *v = findVertex(G, s);
    v->isVisit = TRUE;
    printf("%d\n", v->vName);

    for (IncidentEdge *p = v->iHead; p; p = p->next) {
        Vertex *w = findVertex(G, p->aName);
        if (w->isVisit == FALSE) {
            DFS(G, w->vName);
        }
    }
}