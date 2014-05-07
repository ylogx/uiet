#include <stdio.h>

struct treenode{
    int info;
    struct treenode *left,*right,*father;
};
typedef struct treenode* tnp;

tnp getnode(){
    tnp p= (tnp)malloc(sizeof(struct treenode));
    if(p)
        return p;
    return NULL;//NO_MEM
}
tnp maketree(int data){
    tnp ret=getnode();
    if(!ret){
        printf("Allocation failed\n");
        return NULL;
    }
    ret->info=data;
    ret->left=NULL;
    ret->right=NULL;
    ret->father=NULL;
    return ret;
}

void setleft(tnp in,int data){
    if(in == NULL)
        printf("Void Insertion\n");
    else if(in->left)
        printf("Invalid Insertion - left exists %d\n",in->left->info);
    else{
        in->left=maketree(data);
        in->left->father=in;
    }
}
void setright(tnp in,int data){
    if(!in)
        printf("Void Insertion\n");
    else if(in->right)
        printf("Invalid Insertion - Right exists %d\n",in->right->info);
    else{
        in->right=maketree(data);
        in->right->father=in;
    }
}
int isleft(tnp p){
    return (p->left->father == p) ? 1 :0;
}
void intrav(tnp tree){
    if(!tree)
        return;
    intrav(tree->left);
    printf("%d ",tree->info);
    intrav(tree->right);
}
void intrav5(tnp tree){
    //Non recursive(Iterative traversal) using father field
    tnp p,q;
    p=tree;
    q=NULL;
    do{
        while(p){   //go left
            q=p;
            p=p->left;
        }
        if(q){
            printf("%d\n");
            p=q->right;
        }
        while( q && !p ){   //q not null and p null
            do{
                p=q;
                q=p->father;
            }while(!isleft(p) && q!=NULL);
            if(!q){
                printf("%d\n",q->info);
                p=q->right;
            }
        }
    }while(q);
}

void insert_in_tree(tnp tree,int data){
    tnp p,q;
    p=q=tree;
    while(data != p->info && q){
        p=q;
        q= (data < p->info) ? p->left : p->right;
    }
    if(data < p->info){
        setleft(p,data);
    }else{
        setright(p,data);
    }
}

int main(){
    int data;
    scanf("%d",&data);
    tnp tree=maketree(data);
    while(scanf("%d",&data) != EOF)
        insert_in_tree(tree,data);
    //intrav5(tree);
/*
    tnp tree;
    int num;
    scanf("%d",&num);
    tree= maketree(num);
    while (scanf("%d",&num) != EOF){
        tnp p,q;
        p=q=tree;
        while(num != p->info && q != NULL){
            p=q;
            q= (num < p->info) ? p->left : p->right;
        }

        if(num == p->info)
            setright(p,num);
        else if (num < p->info)
            setleft(p,num);
        else
            setright(p,num);
    }//end while
*/
    printf("Intrav: \n");
    intrav(tree);
    printf("Intrav5: \n");
    intrav5(tree);
    return 0;
}
