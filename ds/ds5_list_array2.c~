/*
		    DS Lab- 5
	   CSE Sec 2, Group 5
	      Oct 3, 2012
	       UE 113090
AIM: Array implementation of Linked Lists
*/
#include<stdio.h>
#include<stdlib.h>

#define NUMNODES 500

struct nodetype {
  ///ptr to a node is represented by an array index
  int info, next;
};
struct nodetype node[NUMNODES];

//*******Global Variable*****
int avail = 0;

int getNode(void){
  ///removes a node from available list and returns a ptr to it
  int p;
  if (avail==-1){   //no nodes available
    printf("\nOverflow");
    exit(1);
  }//end if
  p=avail;
  avail=node[avail].next;
  return(p);
}//end getnode

void freeNode(int p){
  ///returns the node(p) to the available list
  node[p].next=avail;   //appends to avail list
  avail=p;    //new begining of avail list
  return;
}//end freenode

void insAfter(int p,int x){
  ///if p is not null, inserts x into node after the node pointed by p
  int q;
  if(p==-1){
    printf("\nvoid insertion");
    return;
  }
  q=getNode();
  node[q].info=x;
  node[q].next=node[p].next;
  node[p].next=q;
  return;
}//end insert

void delAfter(int p, int *px){
  ///called delAfter(p,&x); deletes node following node(p) and stores the contents of that node in x
  int ptrNext2p;
  if((p==-1)||(node[p].next==-1)){
    printf("\nvoid deletion");
    return;
  }
  ptrNext2p=node[p].next;
  *px=node[ptrNext2p].info;
  node[p].next=node[ptrNext2p].next;
  freeNode(ptrNext2p);
  return;
}//end delete

void display( int p){
  if (p==-1){
    return;
  }
  printf("\t%d",node[p].info);
  p=node[p].next;
  display(p);
}

int main(){
  int i,list=0;   //list starts at 0;
  for(i=0;i<NUMNODES-1;i++)
    node[i].next=i+1;
  node[NUMNODES-1].next=(-1);
  printf("1. Insert After\n");
  printf("2. Delete After\n");
  printf("3. Print\n");
  while(1){
    int query;
    printf("\nEnter operation: ");
    scanf("%d",&query);
    if(query==1){
      int data,ptr;
      printf("\nEnter ptr & data to insert after: ");
      scanf("%d,%d",&ptr,&data);
      insAfter(ptr,data);
    }
    else if(query==2){
      int data,ptr;
      printf("\nEnter ptr to delete after: ");
      scanf("%d",&ptr);
      delAfter(ptr,&data);
      printf("\nData deleted= %d",data);
    }
    else if(query==3){
      printf("The list is ");
      display(list);
      printf("\n");
    }//end q=3
  }//end while
}//end main
