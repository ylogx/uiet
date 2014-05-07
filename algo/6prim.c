/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     Activity Selection Problem via greedy approach
 **/
#include<stdio.h>
#include<stdlib.h>
#define MAX (50)
struct gnode{
    int vertex;
    int weight;
    struct gnode *next;
};
//****Prototype***
void createGraph(struct gnode *adjList[],int num);
void inputGraph(struct gnode *adj[],int num);
void printGraph(struct gnode *adj[],int num);
void deleteGraph(struct gnode *adj[],int num);
void minimumSpanningTreePrim(struct gnode *adj[],int num);
void insertBeg(struct gnode * ptrList, int inVer);

//****main****
int main(){
    struct gnode *adj[MAX];
    int num;
    printf("\nEnter no. of nodes in weighted graph: ");
    scanf("%d",&num);
    num-=1;
    createGraph(adj,num);
    inputGraph(adj,num);
    printGraph(adj,num);
    minimumSpanningTreePrim(adj,num);
    deleteGraph(adj,num);
    return 0;
}
//============FUNCTIONS============
void createGraph(struct gnode *adjList[],int num){
    int i;
    for(i=0;i<num;i++){
        adjList[i]=NULL;
        //adjList[i]=adjList[i]->next;
    }
}
void inputGraph(struct gnode *adj[],int num){
    int i;
    for(i=0;i<num;i++){
        struct gnode *last=NULL,*newPtr;
        int countItem,j;
        printf("Enter no of nodes in adjacency list of node #%d: ",i);
        scanf("%d",&countItem);
        for(j=0;j<countItem;j++){
            int ver,wt;
            printf("Enter node %d: ",j);
            scanf("%d",&ver);
            printf("Enter node %d's weight: ",j);
            scanf("%d",&wt);
            if((newPtr=(struct gnode *)malloc(sizeof(struct gnode)))==NULL){
                printf("\nMemory Error");
                free(newPtr);
                exit(1);
            }
            newPtr->vertex=ver;
            newPtr->weight=wt;
            if(adj[i]==NULL){
                adj[i]=last=newPtr;     //last will help us keep track of end
            }
            else{
                last->next=newPtr;
                last=newPtr;
            }
        }//end for list
    }//end for nodes
}
void printGraph(struct gnode *adj[],int num){
    int i;
    printf("\n\nAdjacency List: \n\n");
    for(i=0;i<num;i++){
        struct gnode *listPtr;
        printf("%d",i+1);
        listPtr=adj[i];
        while(listPtr!=NULL){
            printf("--->\t%d|%d",listPtr->vertex,listPtr->weight);
            listPtr=listPtr->next;
        }
        printf("\n");
    }
}
void deleteGraph(struct gnode *adj[],int num){
    struct gnode * temp;
    int i;
    for(i=0;i<num;i++){
        if(adj[i]->next==NULL){
            free(adj[i]);
        }
        else{
            temp=adj[i];
            while(temp!=NULL){
                struct gnode *temp2;
                temp2=temp;
                temp=temp->next;
                free(temp2);
            }
        }
    }
}
void minimumSpanningTreePrim(struct gnode *adj[],int num){
    typedef enum { UNSEEN, INTREE, NEAR } stat;
    int parent[MAX],status[MAX]={UNSEEN}, nearWt[MAX];
    int stuck, current, edgeCount, minWt, ver, wt, w;
    struct gnode *ptr, *nearList, *ptr2;
    current=0;
    stuck=0;
    status[current]=INTREE;
    edgeCount=0;
    while((edgeCount<=num-1)&&!stuck){
        ptr=adj[current];
        while(ptr!=NULL){
            ver=ptr->vertex;
            wt=ptr->weight;
            if((status[ver]==NEAR) && (wt<nearWt[ver])){
                parent[ver]=current;
                nearWt[ver]=wt;
            }
            else if(status[ver]==UNSEEN){
                status[ver]=NEAR;
                parent[ver]=current;
                insertBeg(nearList,ver);
            }
            ptr=ptr->next;
        }
        if(nearList==NULL){
            stuck=1;    //true;
        }
        else{
            current=nearList->vertex;
            minWt=nearWt[current];
            ptr2=nearList->next;
            while(ptr2!=NULL){
                w=ptr2->vertex;
                if(nearWt[w]<minWt){
                    current=w;
                    minWt=nearWt[w];
                }
                ptr2=ptr2->next;
            }
            //deletelist();     //TODO
            deleteFromList(nearList,current);
            status[current]=INTREE;
            edgeCount+=1;
        }
    }
    for(current=1;current<num;current++){
        printf("(%d,%d)",current,parent[current]);
    }
}
void insertBeg(struct gnode * ptrList, int inVer){
    struct gnode* temp;
    temp = (struct gnode * )malloc(sizeof(struct gnode));
    temp->vertex=inVer;
    temp->next=ptrList;
    ptrList=temp;    
}
void deleteFromList(struct gnode * inList, int inVer){
    int i;
    struct gnode * temp;
    for(i=0;inList->vertex != inVer; i++){
        temp=inList;
        inList=inList->next;
    }
    free(temp->next);
    inList=temp;
    inList->next=NULL;  //val just deleted
}
