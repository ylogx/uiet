/*
		    DS Lab- 5
	   CSE Sec 2, Group 5
	      Oct 17, 2012
	       UE 113090
AIM: Implementation of Postfix using Stack of Linked Lists
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>    //for exponent, pow
struct nodeS {
  int info;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;
//********Global Variables*************
const int TRUE=1;
const int FALSE=0;
char input[30];
NODEPTR start;      //p is a ptr to struct nodeS
//********Functions Prototypes**********
void addop();
void subop();
void mulop();
void divop();
void expop();
//*********of ds7postfix.h*******
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR , int);
int pop(NODEPTR);       //returns data poped
NODEPTR top(NODEPTR );
void display(NODEPTR);      //recursive function, use start->next
//*********Main Function**************
int main(){
    int i,valid=TRUE;
    start=getNode();
    start->info=0;
    start->next=NULL;

    printf("\nEnter Postfix String: ");
    gets(input);
    for(i=0;input[i]!='\0'&&valid;i++){
        //printf("%c\n",input[i]);
        //if(input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'){
            ////push(start,(int)input[i]);
            //printf("%d",input[i]);    //debug
        //}
        //else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='$'){
            //printf("%c",input[i]);    //debug
        //}
        //else{
            //printf("\nInvalid String !\n");
        //}
        switch(input[i]){
            case '0': push(start,0); break;
            case '1': push(start,1); break;
            case '2': push(start,2); break;
            case '3': push(start,3); break;
            case '4': push(start,4); break;
            case '5': push(start,5); break;
            case '6': push(start,6); break;
            case '7': push(start,7); break;
            case '8': push(start,8); break;
            case '9': push(start,9); break;
            case '+': addop(); break;
            case '-': subop(); break;
            case '*': mulop(); break;
            case '/': divop(); break;
            case '$': expop(); break;
            default: printf("\nInvalid String !\n"); valid=FALSE; break;
        }//end switch
    }//end for
    printf("\nValue of expression %s\t=",input);
    display(start->next);
    printf("\n");
    
}//end main
void addop(void){
    int op1,op2,value;
    op2=pop(start);
    op1=pop(start);
    value=op1+op2;
    push(start,value);
}
void subop(void){
    int op1,op2,value;
    op2=pop(start);
    op1=pop(start);
    value=op1-op2;
    push(start,value);
}
void mulop(void){
    int op1,op2,value;
    op2=pop(start);
    op1=pop(start);
    value=op1*op2;
    push(start,value);
}

void divop(void){
    int op1,op2,value;
    op2=pop(start);
    op1=pop(start);
    value=op1/op2;
    push(start,value);
}

void expop(void){
    int op1,op2,value;
    op2=pop(start);
    op1=pop(start);
    value=op1+op2;//pow(op1,op2);
    push(start,value);
}

/*
 *      Implementation of Stack using list
 *
 */

//=====================FUNCTIONS=================================

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
    //printf("\n%d\n",(ptr->next)->info);       //NOTE: useful for debugging postfix problems
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
 
