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

typedef struct IncidentEdge {
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

int n, m;

void initGraph(Graph *G);

void makeVertex(Graph *G, int vName);

void insertEdge(Graph *G, int v1, int v2, int weight);

void insertIncidentEdge(Vertex *v, Edge *e);

Vertex *findVertex(Graph *G, int vName);

int kruskalMST(Graph *G);

Edge *findMinEdge(Graph *G);

void merge(int *s, int u, int v);

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

    printf("%d\n", kruskalMST(G));

    return 0;
}

void initGraph(Graph *G) {
    G->vHead = NULL;
}

void makeVertex(Graph *G, int vName) {
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
    e->isVisit = FALSE;
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
    insertIncidentEdge(p, e);
}

void insertIncidentEdge(Vertex *v, Edge *e) {
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

Vertex *findVertex(Graph *G, int vName) {
    Vertex *p = G->vHead;

    while (p && p->vName != vName) {
        p = p->next;
    }

    return p;
}

int kruskalMST(Graph *G) {
    int *s = (int *) malloc(sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
        s[i] = i;
    }

    int tot = 0;
    int cnt = 0;
    while (cnt < n - 1) {
        Edge *q = findMinEdge(G);
        q->isVisit = TRUE;
        int u = findVertex(G, q->v1)->vName;
        int v = findVertex(G, q->v2)->vName;
        if (s[u] != s[v]) {
            printf(" %d", q->weight);
            tot += q->weight;
            cnt++;
            merge(s, s[u], s[v]);
        }
    }
    printf("\n");

    return tot;
}

Edge *findMinEdge(Graph *G) {
    Edge *q = G->eHead;
    Edge *min = NULL;

    while (q) {
        if (q->isVisit == FALSE) {
            min = q;
            break;
        }
        q = q->next;
    }

    q = min;

    while (q) {
        if (q->isVisit == FALSE && q->weight < min->weight) {
            min = q;
        }
        q = q->next;
    }

    return min;
}

void merge(int *s, int u, int v) {
    for (int i = 1; i <= n; i++) {
        if (s[i] == v) {
            s[i] = u;
        }
    }
}