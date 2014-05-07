#include <stdio.h>

struct node{
    int vertex;
    int weight;
    struct node * next;
};
void createGraph(struct node* adjList[],int num){
    int i;
    for(i=0;i<num;i++){
        adjList[i]=NULL;
    }
}
void inputGraph(struct node* adj[],int num){
    int i;
    for(i=0;i<num;i++){
        struct node *last=NULL;
        int lNodeCount,j;
        printf("\nEnter no of nodes in adjacency of node # %d: ",i);
        scanf("%d",&lNodeCount);
        for(j=0;j<lNodeCount;j++){
            printf("\nEnter node #%d: ",j);
            scanf("%d",&ver);
            printf("\nEnter weight of node#%d: ",j);
            scanf("%d",&wt);
            struct node* newNode=(struct node*)malloc(sizeof(struct node));
            newNode->vertex=ver;
            newNode->weight=wt;
            if(adj[j]==NULL){
                adj[j]=newNode;
                last=newNode;
                //adj[j]=last=newNode;
            }else{
                last->next=newNode;
                last=newNode;
            }
        }//end lists
    }//end nodes
}
void printGraph(struct node* adj[],int num){
    int i;
    printf("\n\nAdjacency List: \n\n");
    for(i=0;i<num;i++){
        int j;
        printf("%d",i);
        ptr=adj[i];
        while(ptr!=NULL){
            printf("->%d",ptr->vertex);
            ptr=ptr->next;
        }
        printf('\n');
    }
}
void deleteGraph(struct node* adj[],int num){
    int i;
    struct node* temp;
    while(i++<num){
        if(adj[i]->next==NULL){
            free(adj[i]);
        }else{
            temp=adj[i];
            while(temp!=NULL){
                struct node* temp2;
                temp2=temp;
                temp=temp->next;
                free(temp2);
            }
        }
    }
}

void shortestPath(struct node* adj[],int num,int ver=0){
    int i;
    int visited[50]={0};
    int dist[50];
    int weightMat[50][50];
    for(i=0;i<num;i++){
        for(j=0;j<num;j++)
            weightMat[i][j]=999;
        //dist[i]=weightMat[ver][i];
        if(adj[i]==NULL){
            dist[i]=999;//int_max
            weight[i][i]=999;
        }else{
            struct node* temp=adj[i];
            while(temp!=NULL){
                if(temp->vertex==ver){
                    dist[i]=temp->weight;
                }
                weightMat[temp->vertex][i]=temp->weight; //creating cost matrix
                temp=temp->next;
            }
        }//end else
    }
    //first node (i.e source) visited
    dist[ver]=0;
    visited[ver]=1;
    for(i=1;i<num;i++){
        if(adj[i]

}

int main(){
    struct node* adjList[50];
    int num,ver;
    printf("\nEnter no of nodes in graph: ");
    scanf("%d",&num);
    num--;
    createGraph(adj,num);
    inputGraph(adj,num);
    printfGraph(adj,num);
    printf("\nEnter initial vertex: ");
    scanf("%d",&ver);
    shortestPath(adj,num,ver);
    return 0;
}
