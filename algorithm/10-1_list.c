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

void print(Graph *G, int vName);

void modifyWeight(Graph *G, int v1, int v2, int weight);

Edge *findEdge(Graph *G, int v1, int v2);

void removeEdge(Graph *G, Edge *e);

void removeIncidentEdge(Vertex *v, IncidentEdge *i);

IncidentEdge *findIncidentEdge(Vertex *v, int aName);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    for (int i = 1; i <= 6; i++) {
        insertVertex(G, i);
    }

    insertEdge(G, 1, 2, 1);
    insertEdge(G, 1, 3, 1);
    insertEdge(G, 1, 4, 1);
    insertEdge(G, 1, 6, 2);
    insertEdge(G, 2, 3, 1);
    insertEdge(G, 3, 5, 4);
    insertEdge(G, 5, 5, 4);
    insertEdge(G, 5, 6, 3);

    while (1) {
        char c;
        scanf("%c", &c);
        if (c == 'a') {
            int vName;
            scanf("%d", &vName);
            print(G, vName);
        } else if (c == 'm') {
            int v1, v2, weight;
            scanf("%d %d %d", &v1, &v2, &weight);
            modifyWeight(G, v1, v2, weight);
        } else if (c == 'q') {
            break;
        }
    }

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
    if (v1 != v2){
        insertIncidentEdge(findVertex(G, v2), v1, e);
    }
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

void print(Graph *G, int vName) {
    Vertex *v = findVertex(G, vName);

    if (v == NULL) {
        printf("-1\n");
        return;
    }

    for (IncidentEdge *p = v->iHead; p; p = p->next) {
        printf(" %d %d", p->aName, p->e->weight);
    }
    printf("\n");
}

void modifyWeight(Graph *G, int v1, int v2, int weight) {
    if (findVertex(G, v1) == NULL || findVertex(G, v2) == NULL) {
        printf("-1\n");
        return;
    }

    Edge *e = findEdge(G, v1, v2);

    if (e == NULL) {
        insertEdge(G, v1, v2, weight);
    } else if (weight == 0) {
        removeEdge(G, e);
    } else {
        e->weight = weight;
    }
}

Edge *findEdge(Graph *G, int v1, int v2) {
    Vertex *v = findVertex(G, v1);

    for (IncidentEdge *p = v->iHead; p; p = p->next) {
        if (p->aName == v2) {
            return p->e;
        }
    }

    return NULL;
}

void removeEdge(Graph *G, Edge *e) {
    Vertex *v1 = findVertex(G, e->v1);
    Vertex *v2 = findVertex(G, e->v2);
    removeIncidentEdge(v1, findIncidentEdge(v1, v2->vName));
    if (v1 != v2) {
        removeIncidentEdge(v2, findIncidentEdge(v2, v1->vName));
    }

    Edge *p = G->eHead;
    if (p == e) {
        G->eHead = e->next;
    } else {
        while (p->next != e) {
            p = p->next;
        }
        p->next = e->next;
    }

    free(e);
}

void removeIncidentEdge(Vertex *v, IncidentEdge *i) {
    IncidentEdge *p = v->iHead;
    if (p == i) {
        v->iHead = i->next;
    } else {
        while (p->next != i) {
            p = p->next;
        }
        p->next = i->next;
    }

    free(i);
}

IncidentEdge *findIncidentEdge(Vertex *v, int aName){
    IncidentEdge *i = v->iHead;

    while (i && i->aName != aName) {
        i = i->next;
    }

    return i;
}