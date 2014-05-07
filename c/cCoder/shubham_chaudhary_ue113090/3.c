//Shubham Chaudhary
#include <stdio.h>
#include<stdlib.h>

struct nodeS {
  int info;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;

NODEPTR getNode(void);
void freeNode(NODEPTR);
/* void insAfter(NODEPTR p,int x); */
/* void delAfter(int p, int *px); */
/* void insert(NODEPTR tempStart,int x); */
void insert(NODEPTR , int);
void delete(NODEPTR , int);
void display(NODEPTR);
void generate(NODEPTR,int,int);
int main(){
    int a,b;
    NODEPTR start;    //p is a ptr to struct nodeS
    start=getNode();
    start->info=0;
    start->next=NULL;
    
    printf("Enter a: ");
    scanf("%d",&(a));
    printf("Enter b: ");
    scanf("%d",&(b));

    generate(start,a,b);
    display(start->next);
  
    return 0;
}

void generate(NODEPTR nd, int a, int b){
    int i,x,y;
    insert(nd,a);
    insert(nd,b);
    x=a; y=b;
    for(i=0;i<20;i++){
        int temp=x+y;
        insert(nd,temp);
        x=y; y=temp;
    }
}

 
NODEPTR getNode(void){
  ///removes a node from available list and returns a ptr to it
  NODEPTR p;
  p=(NODEPTR)malloc(sizeof(struct nodeS));
  return(p);
}//end getnode

void freeNode(NODEPTR  p){
  ///returns the node(p) to the available list
  free(p);
}//end freenode
 
void display(NODEPTR p){
  if (p==NULL){
    return;
  }
  printf("%d\t",p->info);
  p=p->next;
  display(p);
}

void insert(NODEPTR tempStart,int x){
  ///if p is not null, inserts x into node after the node pointed by p
  NODEPTR q;
  q=getNode();
  q->info=x;//info saved in new node
  q->next=NULL;//new node points to null: at end
  //traverse to find last node
  while(tempStart->next!=NULL){
    tempStart=tempStart->next;
  }
  tempStart->next=q;//prev last node containing null now points to new node
}//end insert after


void delete(NODEPTR tempStart,int data){
  NODEPTR ptr;
  ptr=tempStart;
  while(ptr->next!=NULL && (ptr->next)->info!=data){
    //because we need ptr at location before the location to be deleted
    ptr=ptr->next;
    //printf("while");  //debug
  }
  if(ptr->next==NULL){
    printf("\nSorry key %d not found in List ! ",data);
  }
  else{
    NODEPTR temp;
    temp=ptr->next;  //temp points to node to be removed
    ptr->next=temp->next;  //removed node next to ptr
    freeNode(temp);  //free memory
    //printf("else");  //debug
  }
}
