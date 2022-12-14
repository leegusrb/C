#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Edge {
    int v1, v2;
    int weight;
    int isVisit;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    int vName;
    int sack;
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

Vertex *findVertex(Graph *G, int vName);

void KruskalMST(Graph *G);

Edge *findMin(Graph *G);

void merge(Graph *G, int v1, int v2);

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

    KruskalMST(G);

    return 0;
}


void initGraph(Graph *G) {
    G->vHead = NULL;
    G->eHead = NULL;
}

void insertVertex(Graph *G, int vName) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->vName = vName;
    v->sack = vName;
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
    e->isVisit = FALSE;
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
}

Vertex *findVertex(Graph *G, int vName) {
    Vertex *v = G->vHead;

    while (v && v->vName != vName) {
        v = v->next;
    }

    return v;
}

void KruskalMST(Graph *G) {
    int cnt = 0;
    int tot = 0;
    while (cnt < n - 1) {
        Edge *e = findMin(G);
        e->isVisit = TRUE;
        Vertex *v1 = findVertex(G, e->v1);
        Vertex *v2 = findVertex(G, e->v2);
        if (v1->sack != v2->sack) {
            printf(" %d", e->weight);
            cnt++;
            tot += e->weight;
            merge(G, v1->sack, v2->sack);
        }
    }
    printf("\n");

    printf("%d\n", tot);
}

Edge *findMin(Graph *G) {
    Edge *min = NULL;

    for (Edge *p = G->eHead; p; p = p->next) {
        if (p->isVisit == FALSE) {
            min = p;
            break;
        }
    }

    for (Edge *p = min; p; p = p->next) {
        if (p->isVisit == FALSE && p->weight < min->weight) {
            min = p;
        }
    }

    return min;
}

void merge(Graph *G, int v1, int v2) {
    for (Vertex *p = G->vHead; p; p = p->next) {
        if (p->sack == v2) {
            p->sack = v1;
        }
    }
}