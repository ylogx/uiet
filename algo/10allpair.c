/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     All pair shortest path
 **/
#include<stdio.h>
#include<stdlib.h>
#define MAX (50)
struct gnode{
    int vertex;
    int weight;
    struct gnode *next;
};
//---Global Variables---
//****Prototype***
void createGraph(struct gnode *adjList[],int num);
void inputGraph(struct gnode *adj[],int num);
void printGraph(struct gnode *adj[],int num);
void deleteGraph(struct gnode *adj[],int num);

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

//----------------Functions--------------
void allPairShortestPath(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            d[0][i][j]=w[i][j]
//============Graph FUNCTIONS============
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
