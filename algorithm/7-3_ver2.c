#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int key, height;
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
void searchAndFixAfterInsertion(treeType *T, treeNode *w);
void searchAndFixAfterRemoval(treeType *T, treeNode *w);
int isExternal(treeNode *w);
int isInternal(treeNode *w);
int updateHeight(treeNode *w);
int isBalanced(treeNode *w);
treeNode* treeSearch(treeNode *root, int k);
treeNode* sibling(treeNode *w);
treeNode* inOrderSucc(treeNode *w);
treeNode* reduceExternal(treeNode *z);
treeNode* restructure(treeNode *x, treeNode *y, treeNode *z);

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
    searchAndFixAfterInsertion(T, node);
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
        return k;
    }

    searchAndFixAfterRemoval(T, zs->parent);

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
    new->height = 1;
    new->lChild = left;
    new->rChild = right;

    left->parent = new;
    left->height = 0;
    left->lChild = left->rChild = NULL;

    right->parent = new;
    left->height = 0;
    right->lChild = right->rChild = NULL;
}

void preOrder(treeNode *root){
    if(isExternal(root)) return;

    printf(" %d", root->key);
    preOrder(root->lChild);
    preOrder(root->rChild);
}

void searchAndFixAfterInsertion(treeType *T, treeNode *w){
    if(!w->parent) return;
    
    treeNode *z = w->parent;

    while(updateHeight(z) && isBalanced(z)){
        if(!z->parent){
            return;
        }

        z = z->parent;
    }

    if(isBalanced(z)) return;

    treeNode *y, *x;
    if(z->lChild->height > z->rChild->height){
        y = z->lChild;
    }else{
        y = z->rChild;
    }
    if(y->lChild->height > y->rChild->height){
        x = y->lChild;
    }else{
        x = y->rChild;
    }

    treeNode *b = restructure(x, y, z);
    if(!b->parent){
        T->root = b;
    }
}

void searchAndFixAfterRemoval(treeType *T, treeNode *w){
    treeNode *z = w;

    while(updateHeight(z) && isBalanced(z)){
        if(!z->parent) return;

        z = z->parent;
    }

    if(isBalanced(z)) return;

    treeNode *y, *x;
    if(z->lChild->height > z->rChild->height){
        y = z->lChild;
    }else{
        y = z->rChild;
    }
    if(y->lChild->height > y->rChild->height){
        x = y->lChild;
    }else if(y->lChild->height < y->rChild->height){
        x = y->rChild;
    }else{
        if(y == z->lChild){
            x = y->lChild;
        }else{
            x = y->rChild;
        }
    }

    treeNode *b = restructure(x, y, z);

    if(!b->parent){
        T->root = b;
        return;
    }

    searchAndFixAfterRemoval(T, b->parent);
}

int isExternal(treeNode *w){
    return !w->lChild && !w->rChild;
}

int isInternal(treeNode *w){
    return w->lChild || w->rChild;
}

int updateHeight(treeNode *w){
    if(isExternal(w)) return 0;

    int height;

    if(w->lChild->height > w->rChild->height){
        height = w->lChild->height + 1;
    }else{
        height = w->rChild->height + 1;
    }

    if(w->height == height){
        return 0;
    }else{
        w->height = height;
        return 1;
    }
}

int isBalanced(treeNode *w){
    if(isExternal(w)) return 0;

    return w->lChild->height - w->rChild->height > -2 && w->lChild->height - w->rChild->height < 2;
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

treeNode* restructure(treeNode *x, treeNode *y, treeNode *z){
    treeNode *a, *b, *c, *T0, *T1, *T2, *T3;

    if(z->key < y->key && y->key < x->key){
        a = z; b = y; c = x;
        T0 = a->lChild; T1 = b->lChild; T2 = c->lChild; T3 = c->rChild;
    }else if(x->key < y->key && y->key < z->key){
        a = x; b = y; c = z;
        T0 = a->lChild; T1 = a->rChild; T2 = b->rChild; T3 = c->rChild;
    }else if(z->key < x->key && x->key < y->key){
        a = z; b = x; c = y;
        T0 = a->lChild; T1 = b->lChild; T2 = b->rChild; T3 = c->rChild;
    }else if(y->key < x->key && x->key < z->key){
        a = y; b = x; c = z;
        T0 = a->lChild; T1 = b->lChild; T2 = b->rChild; T3 = c->rChild;
    }

    if(!z->parent){
        b->parent = NULL;
    }else if(z->parent->lChild == z){
        z->parent->lChild = b;
        b->parent = z->parent;
    }else{
        z->parent->rChild = b;
        b->parent = z->parent;
    }

    a->lChild = T0; a->rChild = T1;
    T0->parent = T1->parent = a;
    updateHeight(a);

    c->lChild = T2; c->rChild = T3;
    T2->parent = T3->parent = c;
    updateHeight(c);

    b->lChild = a; b->rChild = c;
    a->parent = c->parent = b;
    updateHeight(b);

    return b;
}