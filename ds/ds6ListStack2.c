#include<stdio.h>
#include<stdlib.h>
struct nodeS {
  int info;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;

//*******Global Variable*****
NODEPTR top;

#define TRUE (1)
#define FALSE (0)

//********Functions**********
NODEPTR getNode(void);
void freeNode(NODEPTR);
void display(NODEPTR);
void push(NODEPTR , int);
int pop(NODEPTR );
int empty();

//*********Main**************
int main(){
  NODEPTR start;    // TODO : make it global
  top=start;
  start=getNode();
  start->info=0;
  start->next=NULL;
  
  // TODO : make this a function
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Print\n");
  while(1){
    int query;
    printf("\nEnter operation: ");
    scanf("%d",&query);
    if(query==1){
      int dataPushed;
      printf("\nEnter data to push: ");
      scanf("%d",&dataPushed);
      push(start,dataPushed);
    }
    else if(query==2){
      int dataPoped;
      dataPoped=pop(start);
      printf("\nSuccess: %d popped",dataPoped);
    }
    else if(query==3){
	  printf("The List/Stack is ");
	  display(start->next); //avoid 0 of start node
      printf("\n");
      }//end q=3
    }//end while
    // TODO: make this menu function
  }//end main


//**********************************************************************
//***********************************************************************
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
 

void display(NODEPTR tempStart){
  int i;
  if (tempStart==NULL){
    return;
  }
  for(i=0;i<top&&tempStart!=NULL;i++){
    printf("\t%d",tempStart->info);
    tempStart=tempStart->next;
  }
  //if (p==NULL){
    //return;
  //}
  //printf("\t%d",p->info);
  //p=p->next;
  //display(p);
}



//**************************************************************************
//**************************************************************************


//*************PUSH*********************
void push(NODEPTR tempStart, int elePushed)
{
  //int ele_pushed;
  //printf("Enter ele to be pushed: ");
  //scanf("%d",&ele_pushed);
  NODEPTR temp;
  temp=getNode();
  tempStart->next=temp;
  temp->info=elePushed;
  temp->next=NULL;
  top=temp;
}

//**************POP**********************
int pop(NODEPTR tempStart)
{
  int dataPoped;
  NODEPTR ptr,temp;
  ptr=tempStart;
  if(ptr->next==NULL){
    printf("Stack is empty ! ! !\n");
    return;  //exit pop function
  }
  while((ptr->next)->next!=NULL){
    ptr=ptr->next;
  }
  temp=ptr;
  ptr->next
  return (dataPoped);
}

////////////////Empty///////////////////
int empty()
{
  if(top==0)
    return(TRUE);//TRUE- empty
  else
    return(FALSE);//FALSE- not empty
}
//-----x-----------x-------------x-----------x-----------x--------------

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

int delete(NODEPTR tempStart){
  if(tempStart->next==NULL){
    return(0);
  }
  int dataPoped;
  NODEPTR ptr;
  ptr=tempStart;
  while(ptr->next!=NULL){
    //because we need ptr at location before the location to be deleted
    ptr=ptr->next;
    //printf("while");  //debug
  }
  dataPoped=ptr->info;
  freeNode(ptr->next);
  ptr=NULL;
  return(dataPoped);
  }
