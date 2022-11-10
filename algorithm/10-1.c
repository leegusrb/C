#include <stdio.h>
#include <stdlib.h>

#define swap(v1, v2) {int tmp = v1; v1 = v2; v2 = tmp;}

typedef struct Edge {
    int v1, v2;
    int weight;
    struct Edge *next;
}Edge;

typedef struct IncidentEdge {
    int adjVertex;
    Edge *e;
    struct IncidentEdge *next;
}IncidentEdge;

typedef struct Vertex {
    int vName;
    IncidentEdge *iHead;
    struct Vertex *next;
}Vertex;

typedef struct {
    Vertex *vHead;
    Edge *eHead;
}Graph;

void initGraph(Graph *G);

void insertVertex(Graph *G, int vName);
void insertEdge(Graph *G, int v1, int v2, int weight);
void insertIncidentEdge(Vertex *v, int adjVertex, Edge *e);

void removeEdge(Graph *G, int v1, int v2);
void removeIncidentEdge(Vertex *v, int adjVertex);

void modifyWeight(Graph *G, int v1, int v2, int weight);
void print(Graph *G, int vName);
void printAll(Graph *G);
Vertex *findVertex(Graph *G, int vName);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

    insertVertex(G, 1);
    insertVertex(G, 2);
    insertVertex(G, 3);
    insertVertex(G, 4);
    insertVertex(G, 5);
    insertVertex(G, 6);

    insertEdge(G, 1, 2, 1);
    insertEdge(G, 1, 3, 1);
    insertEdge(G, 1, 4, 1);
    insertEdge(G, 1, 6, 2);
    insertEdge(G, 2, 3, 1);
    insertEdge(G, 3, 5, 4);
    insertEdge(G, 5, 5, 4);
    insertEdge(G, 5, 6, 3);

//    printAll(G);

    while (1) {
        char c;
        scanf("%c", &c);
        if (c == 'a') {
            int vName;
            scanf("%d", &vName);
            print(G, vName);
        } else if (c == 'm') {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            modifyWeight(G, a, b, w);
        } else if (c == 'q') {
            break;
        }
//        printAll(G);
        getchar();
    }

    return 0;
}

void initGraph(Graph *G){
    G->vHead = NULL;
    G->eHead = NULL;
}

void insertVertex(Graph *G, int vName){
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->iHead = NULL;
    v->next = NULL;

    Vertex *p = G->vHead;
    if (!p) {
        G->vHead = v;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = v;
    }
}

void insertEdge(Graph *G, int v1, int v2, int weight){
    if (v1 > v2) swap(v1, v2)
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->v1 = v1;
    e->v2 = v2;
    e->weight = weight;
    e->next = NULL;

    Edge *q = G->eHead;
    if (!q) {
        G->eHead = e;
    } else {
        while (q->next) {
            q = q->next;
        }
        q->next = e;
    }

    Vertex *v = findVertex(G, v1);
    insertIncidentEdge(v, v2, e);
    if (v1 != v2) {
        v = findVertex(G, v2);
        insertIncidentEdge(v, v1, e);
    }
}

void insertIncidentEdge(Vertex *v, int adjVertex, Edge *e){
    IncidentEdge *i = (IncidentEdge *) malloc(sizeof(IncidentEdge));
    i->adjVertex = adjVertex;
    i->e = e;
    i->next = NULL;

    IncidentEdge *p = v->iHead;
    if (!p) {
        v->iHead = i;
    } else if(p->adjVertex > adjVertex) {
        i->next = p;
        v->iHead = i;
    } else {
        while (p->next && p->next->adjVertex < adjVertex) {
            p = p->next;
        }
        i->next = p->next;
        p->next = i;
    }
}

void removeEdge(Graph *G, int v1, int v2) {
    if (v1 > v2) swap(v1, v2)
    Vertex *ver1 = findVertex(G, v1);
    Vertex *ver2 = findVertex(G, v2);
    if (!ver1 || !ver2) {
        printf("-1\n");
        return;
    }
    removeIncidentEdge(ver1, v2);
    if (v1 != v2) {
        removeIncidentEdge(ver2, v1);
    }

    Edge *p = G->eHead;
    Edge *q;
    if (p->v1 == v1 && p->v2 == v2) {
        G->eHead = p->next;
    } else {
        while (p->v1 != v1 || p->v2 != v2) {
            q = p;
            p = p->next;
        }
        q->next = p;
    }

    free(p);
}

void removeIncidentEdge(Vertex *v, int adjVertex){
    IncidentEdge *p = v->iHead;
    IncidentEdge *q;

    if (p->adjVertex == adjVertex) {
        v->iHead = p->next;
    } else {
        while (p->adjVertex != adjVertex) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
    }

    free(p);
}

void modifyWeight(Graph *G, int v1, int v2, int weight){
    if (weight == 0) {
        removeEdge(G, v1, v2);
        return;
    }

    Vertex *p = findVertex(G, v1);

    if (!p || !findVertex(G, v2)) {
        printf("-1\n");
        return;
    }

    IncidentEdge *q = p->iHead;

    while (q) {
        if (q->adjVertex == v2) {
            q->e->weight = weight;
            break;
        } else {
            q = q->next;
        }
    }

    if (!q) {
        insertEdge(G, v1, v2, weight);
    }
}

void print(Graph *G, int vName){
    Vertex *p = findVertex(G, vName);

    if (!p) {
        printf("-1\n");
        return;
    }

    for (IncidentEdge *q = p->iHead; q; q = q->next) {
        printf(" %d %d", q->adjVertex, q->e->weight);
    }
    printf("\n");
}

void printAll(Graph *G){
    for (Vertex *p = G->vHead; p; p = p->next) {
        printf("[%d] : ", p->vName);
        for (IncidentEdge *q = p->iHead; q; q = q->next) {
            printf("[%d]-[%d] ", q->adjVertex, q->e->weight);
        }
        printf("\n");
    }
}

Vertex *findVertex(Graph *G, int vName){
    Vertex *p = G->vHead;

    while (p && p->vName != vName) {
        p = p->next;
    }

    return p;
}