#include <stdio.h>

struct nodetype {
    int info;
    struct nodetype *left, *right, *father, *brother;
};
typedef struct nodetype* nodeptr;
//------ Node Operations --------
nodeptr getnode(){
    nodeptr p;
    p=(nodeptr)malloc(sizeof(struct nodetype));
    if(p)
        return p;
    return NULL;
}//end getNode
//---------- Tree Operations -----------
nodeptr maketree(int init){
    nodeptr p;
    if(! (p=getnode())){
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info = init;
    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
    p->brother=NULL;
    return (p);
}

void setleft(nodeptr p, int x){
    if(p==NULL){
        printf("Void insertion\n");
    }
    else if(p->left != NULL){
        printf("Invalid insertion - left node exists\n");
    }
    else{
        p->left = maketree(x);
        p->left->father = p;
        if(p->right)
            p->left->brother=p->right;
    }
}
void setright(nodeptr p, int x){
    if(p == NULL){
        printf("Void insertion\n");
    }
    else if(p->right != NULL){
        printf("Invalid insertion - right node exists\n");
    }
    else{
        p->right = maketree(x);
        p->right->father = p;
        if(p->left)
            p->right->brother=p->left;
    }
}
int isLeft(nodeptr p){
    if(p->father->left == p)
        return 1;
    return 0;
}
int isRight(nodeptr p){
    if(p->father->right == p)
        return 1;
    return 0;
}

//Recursive Traversals
void intrav(nodeptr tree){
    if(tree){
        intrav(tree->left);
        printf("%d ",tree->info);
        intrav(tree->right);
    }
}
void posttrav(nodeptr tree){
    if(tree){
        posttrav(tree->left);
        posttrav(tree->right);
        printf("%d ",tree->info);
    }
}
void pretrav(nodeptr tree){
    //Depth First Search dfs DFS
    if(tree){
        printf("%d ",tree->info);
        pretrav(tree->left);
        pretrav(tree->right);
    }
}


int main() {
    nodeptr ptree;
    int num;
    scanf("%d",&num);
    ptree= maketree(num);
    while (scanf("%d",&num) != EOF){
        nodeptr p,q;
        p=q=ptree;
        while(num != p->info && q != NULL){
            p=q;
            q= (num < p->info) ? p->left : p->right;
        }
        if(num == p->info)
            printf("no is duplicate\n");
        else if (num < p->info)
            setleft(p,num);
        else
            setright(p,num);
    }//end while
    printf("In Traversal: \n");
    intrav(ptree);
    printf("Post Traversal: \n");
    pretrav(ptree);
    printf("Pre Traversal: \n");
    posttrav(ptree);
    return 0;
}



