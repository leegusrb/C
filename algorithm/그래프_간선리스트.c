#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    char vName;
    struct Vertex *next;
}Vertex;

typedef struct Edge {
    int weight;
    Vertex *v1, *v2;
    struct Edge *next;
}Edge;

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
    e->v1 = findVertex(G, v1);
    e->v2 = findVertex(G, v2);
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
}

void findAdj(Graph *G, char vName) {
    Edge *q = G->eHead;
    Vertex *p = findVertex(G, vName);

    for (; q != NULL; q = q->next) {
        if (q->v1 == p) {
            printf("(%c) ", q->v2->vName);
        } else if (q->v2 == p) {
            printf("(%c) ", q->v1->vName);
        }
    }
}

void print(Graph *G) {
    Edge *q = G->eHead;
    for (; q != NULL; q = q->next) {
        printf("(%c)---%d---(%c)\n", q->v1->vName, q->weight, q->v2->vName);
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

    printf("\n");
    findAdj(&G, 'b');

//    isAdj(&G, 'f', 'a');
//    isAdj(&G, 'a', 'e');

    return 0;
}