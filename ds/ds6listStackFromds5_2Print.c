/*
		    DS Lab- 5
	   CSE Sec 2, Group 5
	      Oct 10, 2012
	       UE 113090
AIM: Implementation of Postfix using Stack of Linked Lists
*/
#include<stdio.h>
#include<stdlib.h>
struct nodeS {
  int info;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;
//*******Global Variable*****
//********Functions Prototypes**********
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR , int);
//void pop(NODEPTR);
int pop(NODEPTR);
NODEPTR top(NODEPTR );
void display(NODEPTR);

//*********Main Function**************
int main(){
  NODEPTR start;    //p is a ptr to struct nodeS
  start=getNode();
  start->info=0;
  start->next=NULL;
  
  printf("1. Push\n");
  printf("2. Pop\n");
//  printf("1. Insert After\n");
//  printf("2. Delete After\n");
  printf("3. Print\n");
  printf("4. Exit\n");
  while(1){
    int query;
    printf("\nEnter operation: ");
    scanf("%d",&query);
    if(query==1){
      int data;
      printf("\nEnter data to push: ");
      scanf("%d",&data);
      push(start,data);
    }
    else if(query==2){
      int dataPoped;
      //pop(start);
      dataPoped=pop(start);
      if(dataPoped!=-1)
        printf("\nSuccessfully Poped %d\n",dataPoped);
      
    }
    else if(query==3){
      printf("The list is ");
      if(start->next==NULL){
        printf("empty\n");
      }
      else{
        display(start->next);
      }
      printf("\n");
    }//end q=3
    else if(query==4){
      printf("\nThank You\n");
      exit(0);
    }
  }//end while
}//end main

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
  printf("\t%d",p->info);
  p=p->next;
  display(p);
}

void push(NODEPTR tempStart,int x){
  ///if p is not null, inserts x into node after the node pointed by p
  NODEPTR q;
  q=getNode();
  q->info=x;//info saved in new node
  q->next=NULL;//new node points to null: at end
  //traverse to find last node
  //while(tempStart->next!=NULL){
    //tempStart=tempStart->next;
  //}
  tempStart=top(tempStart);
  tempStart->next=q;//prev last node containing null now points to new node
}//end insert after

int pop(NODEPTR tempStart){
  NODEPTR ptr;
  ptr=tempStart;
  if(tempStart->next==NULL){
    printf("\nStack UnderFlow\n");
    return(-1);
  }
  else{
    int dataPoped;
    while((ptr->next)->next!=NULL){
      //because we need ptr at location before the location to be deleted
      ptr=ptr->next;
      //printf("while");  //debug
    }
    //ptr=top(ptr);   // TODO
    dataPoped=(ptr->next)->info;
    printf("\n%d\n",(ptr->next)->info);
    //printf("%d",ptr->info);   //debug
    freeNode(ptr->next);  //free memory
    ptr->next=NULL;
    return(dataPoped);
  }
}
NODEPTR top(NODEPTR ptr){
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  return(ptr);
}
