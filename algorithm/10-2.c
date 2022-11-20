#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat[7][7];
} Graph;

void initGraph(Graph *G);

void insertEdge(Graph *G, int v1, int v2, int weight);

void modifyWeight(Graph *G, int v1, int v2, int weight);

void print(Graph *G, int vName);

int main() {
    Graph *G = (Graph *) malloc(sizeof(Graph));
    initGraph(G);

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
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            modifyWeight(G, a, b, w);
        } else if (c == 'q') {
            break;
        }
        getchar();
    }

    return 0;
}

void initGraph(Graph *G) {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            G->mat[i][j] = 0;
        }
    }
}

void insertEdge(Graph *G, int v1, int v2, int weight) {
    G->mat[v1][v2] = weight;
    G->mat[v2][v1] = weight;
}

void modifyWeight(Graph *G, int v1, int v2, int weight) {
    if (v1 < 1 || v1 > 6 || v2 < 1 || v2 > 6) {
        printf("-1\n");
        return;
    }
    
    G->mat[v1][v2] = weight;
    G->mat[v2][v1] = weight;
}

void print(Graph *G, int vName) {
    if (vName < 1 || vName > 6) {
        printf("-1\n");
        return;
    }
    
    for (int i = 1; i <= 6; i++) {
        if (G->mat[vName][i] != 0) {
            printf(" %d %d", i, G->mat[vName][i]);
        }
    }
    printf("\n");
}