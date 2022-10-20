#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int key, height;
    struct treeNode *parent, *lChild, *rChild;
}treeNode;

typedef struct{
    treeNode *root;
}treeType;

void initTree(treeType *T);

treeNode* treeSearch(treeNode *v, int k);
treeNode* sibling(treeNode *z);
int updateHeight(treeNode *w);
int isBalanced(treeNode *w);
treeNode* restructure(treeType *T, treeNode *x, treeNode *y, treeNode *z);

int findElement(treeType *T, int k);

void insertItem(treeType *T, int k);
void expandExternal(treeNode *w);
void searchAndFixAfterInsertion(treeType *T, treeNode *w);

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

int updateHeight(treeNode *w){
    int h;

    if(w->lChild->height > w->rChild->height){
        h = w->lChild->height + 1;
    }else{
        h = w->rChild->height + 1;
    }

    if(h != w->height){
        w->height = h;
        return 1;
    }else{
        return 0;
    }
}

int isBalanced(treeNode *w){
    return (w->lChild->height - w->rChild->height > -2 && w->lChild->height - w->rChild->height < 2);
}

treeNode* restructure(treeType *T, treeNode *x, treeNode *y, treeNode *z){
    // Assign inorder listings of (x, y, z) and their subtrees to (a, b, c) and (T0, T1, T2, T3), resp.
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
    }else{
        a = y; b = x; c = z;
        T0 = a->lChild; T1 = b->lChild; T2 = b->rChild; T3 = c->rChild;
    }

    // Replace the subtree rooted at z with a new subtree rooted at b
    if(T->root == z){
        T->root = b;
        b->parent = NULL;
    }else if(z->parent->lChild == z){
        z->parent->lChild = b;
        b->parent = z->parent;
    }else{
        z->parent->rChild = b;
        b->parent = z->parent;
    }

    //Let T0 and T1 be the left and the right subtree of a, resp.
    a->lChild = T0; a->rChild = T1;
    T0->parent = T1->parent = a;
    updateHeight(a);

    // Let T2 and T3 be the left and the right subtree of c, resp.
    c->lChild = T2; c->rChild = T3;
    T2->parent = T3->parent = c;
    updateHeight(c);

    // Let a and c be the left and the right child of b, resp.
    b->lChild = a; b->rChild = c;
    a->parent = c->parent = b;
    updateHeight(b);

    return b;
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

    if(isInternal(w)){
        return;
    }else{
        w->key = k;
        expandExternal(w);
        searchAndFixAfterInsertion(T, w);
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
    w->height = 1;
}

void searchAndFixAfterInsertion(treeType *T, treeNode *w){
    // Update heights and search for imbalance
    w->lChild->height = 0;
    w->rChild->height = 0;
    w->height = 1;
    
    if(T->root == w){
        return;
    }

    treeNode *z = w->parent;
    while(updateHeight(z) && isBalanced(z)){
        if(T->root == z){
            return;
        }

        z = z->parent;
    }

    if(isBalanced(z)){
        return;
    }

    // Fix imbalance
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

    restructure(T, x, y, z);
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