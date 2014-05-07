/*
 *      Salaria: pg - 333
 *      Implementation of Adjacency List
 * Start: Mon Mar  4 23:45:56 IST 2013
 * Finish:
 */
#include<stdio.h>
#include<malloc.h>
typedef enum {false,true} boolean;
//*************Representation of weighted Graphs********************
#define MAXNODES 50
struct nodeType2{
    int vertex;
    int weight;
    struct nodeType2 *next;
};
typedef struct nodeType2 gnode2;
//gNode2 *adjW[MAXNODES];

struct nodeType1{
    int vertex;
    struct nodeType1 *next;
};
typedef struct nodeType1 gnode1;
//===============PROTOTYPE==================
void createGraph(gnode2 *[],int);
void inputGraph(gnode2 *adj[],int num);
void printGraph(gnode2 *[],int);
void deleteGraph(gnode2 *adj[],int num);
void minimumSpanningTreePrim(gnode2 *adj[],int n);
void insertAtBeginning(gnode1 **fringeList,int d);
void deleteElement(gnode1 **fringeList,int d);
int isEmpty(gnode1 *ptr);
//*********************************************************
int main(){
    gnode2 *adj[MAXNODES];  //NOTE contains only pointers
    int n;
    printf("\nEnter no. of nodes in the graph: ");
    scanf("%d",&n);
    createGraph(adj,n);
    inputGraph(adj,n);
    printf("\n\nInput Graph\n\n");
    printGraph(adj,n);
    printf("****************");
    printf("\n\nMinimum Spanning Tree constitutes following edges\n\n");
    minimumSpanningTreePrim(adj,n);
    getchar();
    deleteGraph(adj,n);
    return 0;
}
//============ F U N C T I O N S ==================
void createGraph(gnode2 *adj[],int num){
    int i;
    for(i=1;i<=num;i++)
        adj[i]=NULL;    //adjW[i]=NULL;
}
void inputGraph(gnode2 *adj[],int num){
    gnode2 *ptr,*last;
    int i,j,m,val,wt;
    for(i=1;i<=num;i++){
        last=NULL;      //New node, so empty
        printf("\nNo. of nodes in the adjacency list of node %d: ",i);
        scanf("%d",&m);
        for(j=1;j<=m;j++){
            ptr=(gnode2 *)malloc(sizeof(gnode2));
            printf("Enter node #%d: ",j);
            scanf("%d",&val);
            ptr->vertex=val;
            printf("Enter node #%d's weight : ",j);
            scanf("%d",&wt);
            ptr->weight=wt;
            ptr->next=NULL;
            if(adj[i]==NULL)    //when there is no node int adjacency list
                adj[i]=last=ptr;
            else{               //when there is already a node in adjacency list e.g 2->1 after 2->1->3
                last->next=ptr;
                last=ptr;
            }
        }//end for
    }
}
void printGraph(gnode2 *adj[],int num){
    gnode2 *ptr;
    int i;
    for(i=1;i<=num;i++){
        ptr=adj[i];
        printf("%d",i);
        while(ptr!=NULL){
            printf("->%d|%d",ptr->vertex,ptr->weight);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
void deleteGraph(gnode2 *adj[],int num){
    int i;
    gnode2 *temp,*ptr;
    for(i=1;i<=num;i++){
        ptr=adj[i];
        while(ptr!=NULL){
            temp=ptr;
            ptr=ptr->next;
            free(temp);
        }
        adj[i]=NULL;
    }
}

//--------PRIM's ALGORITHM---------
void minimumSpanningTreePrim(gnode2 *adj[],int n){
    enum stat { UNSEEN,INTREE,FRINGE };
    gnode1 *fringeList,*ptr2;
    gnode2 *ptr1;
    int i,x,stuck,w,edgeCount,minWt,y,weight;
    int parent[MAXNODES],status[MAXNODES],fringeWt[MAXNODES];
    fringeList=NULL;
    for(i=1;i<=n;i++)
        status[i]=UNSEEN;
    x=1;
    status[x]=INTREE;
    edgeCount=0;
    stuck=false;
    while((edgeCount<=(n-1))&&(!stuck)){
        ptr1=adj[x];
        while(ptr1!=NULL){
            y=ptr1->vertex;
            weight=ptr1->weight;
            if((status[y]==FRINGE)&&(weight<fringeWt[y])){
                parent[y]=x;
                fringeWt[y]=weight;
                } else if(status[y]==UNSEEN){
                status[y]=FRINGE;
                parent[y]=x;
                fringeWt[y]=weight;
                insertAtBeginning(&fringeList,y);   //TODO
            }
            ptr1=ptr1->next;
        }
        if(isEmpty(fringeList))             //TODO
            stuck = true;
        else{
            x=fringeList->vertex;
            minWt=fringeWt[x];
            ptr2=fringeList->next;
            while(ptr2!=NULL){
                w=ptr2->vertex;
                if(fringeWt[w]<minWt){
                    x=w;
                    minWt=fringeWt[w];
                }
                ptr2=ptr2->next;
            }
            deleteElement(&fringeList,x);   //TODO
            status[x]=INTREE;
            edgeCount+=1;
        }
    }
    for(x=2;x<=n;x++)
        printf("(%d,%d)\n",x,parent[x]);
}

//******List Functions******
void insertAtBeginning(gnode1 **fringeList,int d){
    gnode1 *ptr;
    ptr=(gnode1 *)malloc(sizeof(gnode1));
    ptr->vertex=d;
    ptr->next=*fringeList;
    *fringeList=ptr;
}
void deleteElement(gnode1 **fringeList,int d){
    gnode1 *loc, *ploc;
    if(d==(*fringeList)->vertex){
        loc=*fringeList;
        *fringeList=(*fringeList)->next;
        free(loc);
    }
    else{
        ploc=*fringeList;
        loc=(*fringeList)->next;
        while(loc->vertex!=d){
            ploc=loc;
            loc=loc->next;
        }
        ploc->next=loc->next;
        free(loc);
    }
}
int isEmpty(gnode1 *ptr){
    return ((ptr==NULL) ? (1) : (0) );
    //if (ptr==NULL) 
    //    return (1);
    //return (0) ;
}

/* ******************
Enter no. of nodes in the graph: 7

No. of nodes in the adjacency list of node 1: 3
Enter node #1: 2
Enter node #1's weight : 2
Enter node #2: 5
Enter node #2's weight : 3
Enter node #3: 4 7
Enter node #3's weight : 
No. of nodes in the adjacency list of node 2: 4
Enter node #1: 5 6 6 4 3 2 1 2
Enter node #1's weight : Enter node #2: Enter node #2's weight : Enter node #3: Enter node #3's weight : Enter node #4: Enter node #4's weight : 
No. of nodes in the adjacency list of node 3: 5
Enter node #1: 5 4 4 5 2 2 6 2 7 1
Enter node #1's weight : Enter node #2: Enter node #2's weight : Enter node #3: Enter node #3's weight : Enter node #4: Enter node #4's weight : Enter node #5: Enter node #5's weight : 
No. of nodes in the adjacency list of node 4: 4
Enter node #1: 1 7 5 1 3 5 7 6
Enter node #1's weight : Enter node #2: Enter node #2's weight : Enter node #3: Enter node #3's weight : Enter node #4: Enter node #4's weight : 
No. of nodes in the adjacency list of node 5: 4
Enter node #1: 1 3 2 6 3 4 4 1
Enter node #1's weight : Enter node #2: Enter node #2's weight : Enter node #3: Enter node #3's weight : Enter node #4: Enter node #4's weight : 
No. of nodes in the adjacency list of node 6: 2
Enter node #1: 2 4 3 2
Enter node #1's weight : Enter node #2: Enter node #2's weight : 
No. of nodes in the adjacency list of node 7: 2
Enter node #1: 4 6 3 1
Enter node #1's weight : Enter node #2: Enter node #2's weight : 

Input Graph

1->2|2->5|3->4|7
2->5|6->6|4->3|2->1|2
3->5|4->4|5->2|2->6|2->7|1
4->1|7->5|1->3|5->7|6
5->1|3->2|6->3|4->4|1
6->2|4->3|2
7->4|6->3|1
****************

Minimum Spanning Tree constitutes following edges

(2,1)
(3,2)
(4,5)
(5,1)
(6,3)
(7,3)


------------------
(program exited with code: 0)
**********************/
