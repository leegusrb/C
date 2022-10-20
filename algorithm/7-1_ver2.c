#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int key;
    struct treeNode *parent, *lChild, *rChild;
}treeNode;

typedef struct{
    treeNode *root;
}treeType;

void insertItem(treeType *root, int k);
int removeElement(treeType *root, int k);
int findElement(treeType *root, int k);
void print(treeType *T);

void init(treeType *T);
void makeNewNode(treeNode *new, int k);
void preOrder(treeNode *root);
int isExternal(treeNode *w);
int isInternal(treeNode *w);
treeNode* treeSearch(treeNode *root, int k);
treeNode* sibling(treeNode *w);
treeNode* inOrderSucc(treeNode *w);
treeNode* reduceExternal(treeNode *z);

int main(){
    treeType *T = (treeType *)malloc(sizeof(treeType));
    char c;
    int k;

    init(T);

    while(1){
        scanf("%c", &c);
        if(c == 'i'){
            scanf("%d", &k);
            insertItem(T, k);
        }else if(c == 'd'){
            scanf("%d", &k);
            int tmp = removeElement(T, k);
            if(tmp){
                printf("%d\n", tmp);
            }else{
                printf("X\n");
            }
        }else if(c == 's'){
            scanf("%d", &k);
            int tmp = findElement(T, k);
            if(tmp){
                printf("%d\n", tmp);
            }else{
                printf("X\n");
            }
        }else if(c == 'p'){
            print(T);
        }else if(c == 'q'){
            break;
        }
        getchar();
    }

    return 0;
}

void insertItem(treeType *T, int k){
    treeNode *node = treeSearch(T->root, k);

    if(isInternal(node)) return;
    
    makeNewNode(node, k);
}

int removeElement(treeType *T, int k){
    treeNode *w = treeSearch(T->root, k);

    if(isExternal(w)) return 0;

    treeNode *z, *zs;

    if(isExternal(w->lChild) || isExternal(w->rChild)){
        if(isInternal(w->lChild)){
            z = w->rChild;
        }else{
            z = w->lChild;
        }
        zs = reduceExternal(z);
    }else{
        treeNode *y = inOrderSucc(w);
        w->key = y->key;
        zs = reduceExternal(y->lChild);
    }

    if(!zs->parent){
        T->root = zs;
    }

    return k;
}

int findElement(treeType *T, int k){
    treeNode *w = treeSearch(T->root, k);

    if(isExternal(w)){
        return 0;
    }else{
        return k;
    }
}

void print(treeType *T){
    preOrder(T->root);
    printf("\n");
}

void init(treeType *T){
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    root->parent = root->lChild = root->rChild = NULL;

    T->root = root;
}

void makeNewNode(treeNode *new, int k){
    treeNode *left = (treeNode *)malloc(sizeof(treeNode));
    treeNode *right = (treeNode *)malloc(sizeof(treeNode));

    new->key = k;
    new->lChild = left;
    new->rChild = right;

    left->parent = new;
    left->lChild = left->rChild = NULL;

    right->parent = new;
    right->lChild = right->rChild = NULL;
}

void preOrder(treeNode *root){
    if(isExternal(root)) return;

    printf(" %d", root->key);
    preOrder(root->lChild);
    preOrder(root->rChild);
}

int isExternal(treeNode *w){
    return !w->lChild && !w->rChild;
}

int isInternal(treeNode *w){
    return w->lChild || w->rChild;
}

treeNode* sibling(treeNode *w){
    if(w->parent->lChild == w){
        return w->parent->rChild;
    }else{
        return w->parent->lChild;
    }
}

treeNode* inOrderSucc(treeNode *w){
    w = w->rChild;

    while(isInternal(w->lChild)){
        w = w->lChild;
    }

    return w;
}

treeNode* reduceExternal(treeNode *z){
    treeNode *w = z->parent;
    treeNode *zs = sibling(z);

    if(!w->parent){
        zs->parent = NULL;
    }else{
        treeNode *g = w->parent;
        zs->parent = g;
        if(w == g->lChild){
            g->lChild = zs;
        }else{
            g->rChild = zs;
        }
    }

    free(w);
    free(z);

    return zs;
}

treeNode* treeSearch(treeNode *root, int k){
    if(isExternal(root) || k == root->key){
        return root;
    }else if(k < root->key){
        return treeSearch(root->lChild, k);
    }else{
        return treeSearch(root->rChild, k);
    }
}