/*
 *      Implementation of Stack using list
 *
 */
#include<stdio.h>
#include<stdlib.h>
struct nodeS {
  int info;
  struct nodeS *top;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;
//*******Global Variable*****
//********Functions Prototypes**********
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR *, int);
int pop(NODEPTR *);       //returns data poped
void display(NODEPTR);  //pass top

//=====================FUNCTIONS=================================
/*
  NODEPTR start;    //p is a ptr to struct nodeS
  start=getNode();
  start->info=0;
  start->next=NULL;
  top=start;
      push(top,data);
      dataPoped=pop(top);
      if(dataPoped!=-1)
        printf("\nSuccessfully Poped %d\n",dataPoped);
      printf("The Stack is ");
      if(top->next==NULL){
        printf("empty\n");
      }
      else{
        printf("\n------------------------------------------\n");
        display(top);
 */

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
  if (p->next==NULL){
    return;
  }
  //printf("-----------------------------------");
  printf("\t%d",p->info);
  //printf("-----------------------------------");
  p=p->next;
  display(p);
}

void push(NODEPTR *tempTop,int x){
  ///if p is not null, inserts x into node after the node pointed by p
  NODEPTR q;
  q=getNode();
  q->info=x;//info saved in new node
  q->next=*tempTop;//NOTE next points to the previous item on stack
  //traverse to find last node
  //tempStart=top(tempStart);
  *tempTop=q;//prev last node containing null now points to new node
}//end insert after

int pop(NODEPTR *tempTop){
  //NODEPTR ptr;
  //ptr=tempStart;
  if((*tempTop)->next==NULL){//if node before top is null
    printf("\nStack UnderFlow\n");
    return(-1);
  }
  else{
    int dataPoped;
    NODEPTR temp;
    dataPoped=(*tempTop)->info;//84
    //printf("\n%d\n",(tempTop)->info);  //debug
    //printf("%d",ptr->info);   //debug
    temp=*tempTop;
    *tempTop=(*tempTop)->next;//top points to prev node  //NOTE modifies global variable !
    freeNode(temp);  //free memory
    //ptr->next=NULL;
    //TODO make this top's location one before current position
    return(dataPoped);
  }
}
