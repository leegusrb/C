#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int weight;
    char v1, v2;
    struct Edge *next;
}Edge;

typedef struct IncidentEdge {
    char adjVertex;
    Edge *e;
    struct IncidentEdge *next;
}IncidentEdge;

typedef struct Vertex {
    char vName;
    IncidentEdge *iHead;
    struct Vertex *next;
}Vertex;

typedef struct {
    Vertex *vHead;
    Edge *eHead;
}Graph;

void init (Graph *G) {
    G->vHead = NULL;
    G->eHead = NULL;
}

void makeVertices(Graph *G, char vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->iHead = NULL;
    v->next = NULL;
    Vertex *q = G->vHead;

    if (q == NULL) {
        G->vHead = v;
    } else {
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = v;
    }
}

void insertIncidentEdge(Vertex *v, char av, Edge *e) {
    IncidentEdge *p = (IncidentEdge *) malloc(sizeof(IncidentEdge));
    p->adjVertex = av;
    p->e = e;
    p->next = NULL;

    IncidentEdge *q = v->iHead;
    if (q == NULL) {
        v->iHead = p;
    } else {
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

Vertex *findVertex(Graph *G, char vName) {
    Vertex *p = G->vHead;
    while (p->vName != vName) {
        p = p->next;
    }

    return p;
}

void insertEdges(Graph *G, int w, char v1, char v2) {
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->weight = w;
    e->v1 = v1;
    e->v2 = v2;
    e->next = NULL;

    Edge *q = G->eHead;
    if (q == NULL) {
        G->eHead = e;
    } else {
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = e;
    }

    Vertex *v = findVertex(G, v1);
    insertIncidentEdge(v, v2, e);
    v = findVertex(G, v2);
    insertIncidentEdge(v, v1, e);
}

void modifyWeight(Graph *G, char v1, char v2, int w) {
    Vertex *p = findVertex(G, v1);
    IncidentEdge *q = p->iHead;

    while (q) {
        if (q->adjVertex == v2) {
            q->e->weight = w;
            break;
        } else {
            q = q->next;
        }
    }
}

void print(Graph *G) {
    Vertex *p = G->vHead;
    IncidentEdge *q;

    for (; p != NULL; p = p->next) {
        printf("[%c] : ", p->vName);
        for (q = p->iHead; q != NULL; q = q->next) {
            printf("[%c, %d]", q->adjVertex, q->e->weight);
        }
        printf("\n");
    }
}

int main() {
    Graph G;
    init(&G);

    makeVertices(&G, 'a');
    makeVertices(&G, 'b');
    makeVertices(&G, 'c');
    makeVertices(&G, 'd');
    makeVertices(&G, 'e');
    makeVertices(&G, 'f');

    insertEdges(&G, 1, 'a', 'b');
    insertEdges(&G, 1, 'a', 'c');
    insertEdges(&G, 1, 'a', 'd');
    insertEdges(&G, 2, 'a', 'f');
    insertEdges(&G, 1, 'b', 'c');
    insertEdges(&G, 4, 'c', 'e');
    insertEdges(&G, 4, 'e', 'e');
    insertEdges(&G, 3, 'e', 'f');

    print(&G);

    modifyWeight(&G, 'a', 'b', 3);
    print(&G);

    return 0;
}