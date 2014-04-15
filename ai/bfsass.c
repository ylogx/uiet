#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 20
#define QSIZE 20
#define TRUE 1
#define FALSE 0
//********Global Variables*******
struct queue{
    int qarr[QSIZE];
    int front,rear,ele_last_rem;
};
struct gnode{
    int ver;
    struct gnode * next;
};
//********Functions Used*********
void enqueue(struct queue*,int);
int dequeue(struct queue*);      //output is the element deleted
int isNotEmpty(struct queue* q);     //output true or false
int isFull(struct queue* q);      //output true or false
void init(struct queue* q){  q->front= -1; q->rear= -1; }
void display(struct queue* q);
//*******************************
//%%%%%% Breadth First Search %%%%%%%%%
//@@@@@@ from OCW 6.006-lec13 @@@@@@@@@
void bfs(struct gnode **adj,int num,int source){
    unsigned int level[MAXNODES]={-1};
    int parent[MAXNODES];
    struct queue frontier;
    init(&frontier);
    int i;
    //initialisation
    i=source;
    level[i]=0;     //level of source = 0
    parent[i]=-1;   //parent NULL(=intMax)
    enqueue(&frontier,i);
    //traversing
    while(isNotEmpty(&frontier)){
        printf("isnotempty***");
        int u;
        u=dequeue(&frontier);
        while(u != -2){
            struct gnode * v=adj[u];
            while(v->next!=NULL){
                if(level[v->ver] == 0){
                    level[v->ver]=i;
                    parent[v->ver]=u;
                    enqueue(&frontier,v->ver);
                }
                v=v->next;
            }
            u=dequeue(&frontier);
        }
        i+=1;
    }
    printf("\n\n##############\nTree is: \n");
    printf("%d\t",6);
    for(i=0;i<MAXNODES;i++)
        printf("%d\t",level[i]);
    //~ 
    int print=parent[3];
    while(print != -1){
        printf("%d\t",print);
        print=parent[print];
    }
}
void createGraph(struct gnode **adj,int num){
    int i;
    for(i=0;i<num;i++){
        adj[i]=NULL;
    }
}
void inputGraph(struct gnode **adj,int num){
    int i,noNode;
    for(i=0;i<num;i++){
        int j;
        struct gnode * last;
        printf("\nNo. of nodes in the adjacency list of node %d: ",i);
        scanf("%d",&noNode);
        for(j=0;j<noNode;j++){
            int input;
            printf("Enter node #%d: ",j);
            scanf("%d",&input);
            struct gnode *temp=(struct gnode *)malloc(sizeof(struct gnode));
            temp->ver=input;
            temp->next=NULL;
            if(adj[i]){
                last->next=temp;
                last=temp;
            }else{
                adj[i]=last=temp;
            }
        }
    }
}
/*
        DS Lab- 3
       CSE Sec 2, Group 5
    Implementation of Queue using arrays
*/
//############## Main Function ################
int main(){
    struct gnode * adj[MAXNODES];   //array of pointers
    int n;
    printf("\nEnter no. of nodes in the graph: ");
    scanf("%d",&n);
    createGraph(adj,n);
    inputGraph(adj,n);
    bfs(adj,n,1);
    return 0;
}
//############################################
//****Display Function**********
void display(struct queue* q)
{
    int i;
    if (q->front == - 1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        for (i = q->front; i <= q->rear; i++)
            printf("%d ", q->qarr[i]);
        printf("\n");
    }
}
//******Empty******
int isNotEmpty(struct queue* q)
{
  if(q->front==q->rear)
  {
    return(FALSE);  //empty
  }
  else
    return(TRUE);
}

//*****Full*******
int isFull(struct queue* q)
{
  if(q->rear==QSIZE)
  {
    return(TRUE);
  }
  else
  return(FALSE);
}

//*****insert******
void enqueue(struct queue* q,int added_item)
{
    if (q->rear == QSIZE - 1)
    printf("Queue Overflow\n");
    else
    {
        if (q->front == - 1)
        /*If queue is initially empty */
        q->front = 0;
        q->rear += 1;
        q->qarr[q->rear] = added_item;
    }
  printf("\nElement %d successfully inserted in the Queue",added_item);
  //display(q);
}

//*****remove*******
int dequeue(struct queue* q)
{
    if (q->front == - 1 || q->front > q->rear)
    {
        printf("Queue Underflow\n");
        return -2;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q->qarr[q->front]);
        q->front += 1;
    }
  return(q->qarr[q->front-1]);
}
