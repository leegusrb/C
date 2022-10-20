#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int key;
    struct treeNode *parent, *lChild, *rChild;
}treeNode;

typedef struct{
    treeNode *root;
}treeType;

void initTree(treeType *T);

treeNode* treeSearch(treeNode *v, int k);
treeNode* sibling(treeNode *z);

int findElement(treeType *T, int k);

void insertItem(treeType *T, int k);
void expandExternal(treeNode *w);

int removeElement(treeType *T, int k);
void reduceExternal(treeType *T, treeNode *z);
treeNode* inOrderSucc(treeNode *w);

void print(treeType *T);
void preOrder(treeNode *p);

int isExternal(treeNode *v);
int isInternal(treeNode *v);

int main(){
    treeType T;
    char c;
    int k;

    initTree(&T);

    while(1){
        scanf("%c", &c);
        if(c == 'i'){
            scanf("%d", &k);
            insertItem(&T, k);
        }else if(c == 'd'){
            scanf("%d", &k);
            int e = removeElement(&T, k);
            if(e){
                printf("%d\n", e);
            }else{
                printf("X\n");
            }
        }else if(c == 's'){
            scanf("%d", &k);
            int e = findElement(&T, k);
            if(e){
                printf("%d\n", e);
            }else{
                printf("X\n");
            }
        }else if(c == 'p'){
            print(&T);
        }else if(c == 'q'){
            break;
        }
        getchar();
    }

    return 0;
}

void initTree(treeType *T){
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    root->lChild = root->rChild = root->parent = NULL;

    T->root = root;
}

treeNode* treeSearch(treeNode *v, int k){
    if(isExternal(v)){
        return v;
    }

    if(k == v->key){
        return v;
    }else if(k < v->key){
        return treeSearch(v->lChild, k);
    }else{
        return treeSearch(v->rChild, k);
    }
}

treeNode* sibling(treeNode *z){
    if(z->parent->lChild == z){
        return z->parent->rChild;
    }else{
        return z->parent->lChild;
    }
}

int findElement(treeType *T, int k){
    treeNode *w = treeSearch(T->root, k);

    if(isExternal(w)){
        return 0;
    }else{
        return w->key;
    }
}

void insertItem(treeType *T, int k){
    treeNode *w = treeSearch(T->root, k);

    if(!isExternal(w)){
        return;
    }else{
        w->key = k;
        expandExternal(w);
    }
}

void expandExternal(treeNode *w){
    treeNode *l = (treeNode *)malloc(sizeof(treeNode));
    treeNode *r = (treeNode *)malloc(sizeof(treeNode));

    l->lChild = l->rChild = NULL;
    l->parent = w;

    r->lChild = r->rChild = NULL;
    r->parent = w;

    w->lChild = l;
    w->rChild = r;
}

int removeElement(treeType *T, int k){
    treeNode *w = treeSearch(T->root, k);

    if(isExternal(w)){
        return 0;
    }

    treeNode *z = w->lChild;

    if(!isExternal(z)){
        z = w->rChild;
    }
    if(isExternal(z)){
        reduceExternal(T, z);
    }else{
        treeNode *y = inOrderSucc(w);
        z = y->lChild;
        w->key = y->key;
        reduceExternal(T, z);
    }

    return k;
}

void reduceExternal(treeType *T, treeNode *z){
    treeNode *w = z->parent;
    treeNode *zs = sibling(z);

    if(T->root == w){
        T->root = zs;
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

    free(z);
    free(w);
}

treeNode* inOrderSucc(treeNode *w){
    w = w->rChild;
    while(isInternal(w->lChild)){
        w = w->lChild;
    }
    return w;
}

void print(treeType *T){
    preOrder(T->root);
    printf("\n");
}

void preOrder(treeNode *p){
    if(isExternal(p)){
        return;
    }

    printf(" %d", p->key);
    preOrder(p->lChild);
    preOrder(p->rChild);
}

int isExternal(treeNode *v){
    return (!v->lChild && !v->rChild);
}

int isInternal(treeNode *v){
    return (v->lChild || v->rChild);
}