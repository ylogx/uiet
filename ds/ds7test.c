//to test ds7postfix.h header file
#include<stdio.h>
#include<stdlib.h>
#include"ds7postfix.h"      //contains functions for stack implementation; reduces complexity
//********Global Variables*************
const int TRUE=1;
const int FALSE=0;
char input[30];
NODEPTR start,top;      //p is a ptr to struct nodeS
//********Functions Prototypes**********
void addop();
void postfix(char *);
//*********of ds7postfix.h*******
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR *, int);
int pop(NODEPTR *);       //returns data poped
void display(NODEPTR);  //pass top
//*********Main Function**************
int main(){
    start=getNode();
    start->info=0;
    start->next=NULL;
    top=start;
    printf("\nEnter Postfix String: ");
    gets(input);
    postfix(input);
    printf("\nValue of expression %s\t=",input);
    display(top);
    printf("\n");
    
}//end main
void postfix(char *input){
  int i,valid=TRUE;
  for(i=0;input[i]!='\0'&&valid;i++){
    switch(input[i]){
    case '1': push(&top,1); break;
    case '2': push(&top,2); break;
    case '3': push(&top,3); break;
    case '4': push(&top,4); break;
    case '5': push(&top,5); break;
/*
    case '0': push(start,0); break;
    case '6': push(start,6); break;
    case '7': push(start,7); break;
    case '8': push(start,8); break;
    case '9': push(start,9); break;  
 */  
    case '+': addop(); break;
    default: printf("\nInvalid String !\n"); valid=FALSE; break;
    }//end switch
  }//end for
  
}
void addop(void){
    int op1,op2,value;
    op2=pop(&top);
    op1=pop(&top);
    value=op1+op2;
    push(&top,value);
/*
    op2=pop(start);
    op1=pop(start);
    value=op1+op2;
    push(start,value);
 */
}


