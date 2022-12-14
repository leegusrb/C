#include <stdio.h>
#include <stdlib.h>

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
    IncidentEdge *iHead;
    struct Vertex *next;
} Vertex;

typedef struct {
    Vertex *vHead;
    Edge *eHead;
} Graph;

void initGraph(Graph *G);

void insertVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2, int weight);

void insertIncidentEdge(Vertex *v, int aName, Edge *e);

Vertex *findVertex(Graph *G, int vName);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    /**
     * insertVertices
     * insertVertex(G, vName);
     */
    
    /**
     * insertEdges
     * insertEdge(G, v1, v2, weight);
     */

    return 0;
}


void initGraph(Graph *G) {
    G->vHead = NULL;
    G->eHead = NULL;
}

void insertVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
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