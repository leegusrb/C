#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int element;
    struct List *next;
} List;

typedef struct {
    char name;
    List *outEdges;
    List *inEdges;
    int inDegree;
} Vertex;

typedef struct {
    int origin;
    int destination;
} Edge;

typedef struct {
    Vertex *vertices;
    Edge *edges;
} Graph;

typedef struct {
    int *elem;
    int front, rear;
} Queue;

Graph *G;
int n, m;
int *topOrder;
Queue *Q;

void initGraph();

void buildGraph();

void insertVertex(char vName, int i);

void insertDirectedEdge(char uName, char wName, int i);

int index(char vName);

void addFirst(List *H, int i);

void topologicalSort();

void initQueue();

int isEmpty();

void enqueue(int elem);

int dequeue();

int main() {
    buildGraph();

    topologicalSort();

    if (topOrder[0] == 0) {
        printf("0\n");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%c ", G->vertices[topOrder[i]].name);
        }
    }

    return 0;
}

void initGraph() {
    G = (Graph *) malloc(sizeof(Graph));
}

void buildGraph() {
    initGraph();

    scanf("%d", &n);
    G->vertices = (Vertex *) malloc(sizeof(Vertex) * n);

    for (int i = 0; i < n; i++) {
        char vName;
        getchar();
        scanf("%c", &vName);
        insertVertex(vName, i);
    }

    scanf("%d", &m);
    G->edges = (Edge *) malloc(sizeof(Edge) * m);

    for (int i = 0; i < m; i++) {
        char uName, wName;
        getchar();
        scanf("%c %c", &uName, &wName);
        insertDirectedEdge(uName, wName, i);
    }
}

void insertVertex(char vName, int i) {
    G->vertices[i].name = vName;
    G->vertices[i].outEdges = (List *) malloc(sizeof(List));
    G->vertices[i].outEdges->next = NULL;
    G->vertices[i].inEdges = (List *) malloc(sizeof(List));
    G->vertices[i].inEdges->next = NULL;
    G->vertices[i].inDegree = 0;
}

void insertDirectedEdge(char uName, char wName, int i) {
    int u = index(uName);
    int w = index(wName);

    G->edges[i].origin = u;
    G->edges[i].destination = w;

    addFirst(G->vertices[u].outEdges, i);
    addFirst(G->vertices[w].inEdges, i);
    
    G->vertices[w].inDegree++;
}

int index(char vName) {
    for (int i = 0; i < n; i++) {
        if (G->vertices[i].name == vName) {
            return i;
        }
    }

    return -1;
}

void addFirst(List *H, int i) {
    List *node = (List *) malloc(sizeof(List));
    node->element = i;
    node->next = H->next;
    H->next = node;
}

void topologicalSort() {
    initQueue();

    int *in = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        Vertex u = G->vertices[i];
        in[i] = u.inDegree;
        if (in[i] == 0) {
            enqueue(i);
        }
    }

    topOrder = (int *) malloc(sizeof(int) * (n + 1));
    int t = 1;

    while (!isEmpty()) {
        int u = dequeue();
        topOrder[t++] = u;

        List *p = G->vertices[u].outEdges->next;
        while (p != NULL) {
            int e = p->element;
            int w = G->edges[e].destination;
            in[w]--;
            if (in[w] == 0) {
                enqueue(w);
            }

            p = p->next;
        }
    }

    if (t <= n) {
        topOrder[0] = 0;
    } else {
        topOrder[0] = 1;
    }
}

void initQueue() {
    Q = (Queue *) malloc(sizeof(Queue));
    Q->elem = (int *) malloc(sizeof(int) * n);
    Q->front = 0;
    Q->rear = 0;
}

int isEmpty() {
    return Q->front == Q->rear;
}

void enqueue(int elem) {
    Q->rear = (Q->rear + 1) % n;
    Q->elem[Q->rear] = elem;
}

int dequeue() {
    Q->front = (Q->front + 1) % n;
    return Q->elem[Q->front];
}

