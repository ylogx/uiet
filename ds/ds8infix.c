/*
 *		    DS Lab- 8
 *	   CSE Sec 2, Group 5
 *	      Oct 17, 2012
 *	       UE 113090
 * AIM: Solution of Infix (converted to Postfix)
 *      using Stack of Linked Lists
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>    //for exponent, pow
#include"ds7postfix.h"      //contains functions for stack implementation
//#include"ds7postfix.c"      //for solution of postfix string

//********Global Variables*************
const int TRUE=1;
const int FALSE=0;
char infix[30], postfix[30];
NODEPTR stack;      //p is a ptr to struct nodeS

//********Functions Prototypes**********
void in2post(char *);
int prcd(char,char);
//*********of ds7postfix.c*******
void addop();
void subop();
void mulop();
void divop();
void expop();
void postfix(char *);
//*********of ds7postfix.h*******
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR *, int);
int pop(NODEPTR *);       //returns data poped
void display(NODEPTR);  //pass top
//********* MAIN Function **************
int main(){
    stack=getNode();
    stack->info=0;
    stack->next=NULL;
    stack->top=start;

    printf("\nEnter Infix String: ");
    gets(infix);

    in2post(infix);
    printf("\n");

}//end main

in2post(char *inf){
    if(stack->top)->next!=NULL&&symb!=')'){
        push(&(stack->top),symb);
    else
        topsymb=pop(&(stack->top));
}

int prcd(char op1,char op2){
    //(,)=false
    //op,(=false
    //(,op=false
    //op,)=true
    if(op1=='('&&op2==')')
        return(FALSE);
    else if(op1=='(')
        return(FALSE);
    if(op2=='(')
        return(FALSE);
    if(op2==')')
        return(TRUE);
    if(op1==('*'||'/')&&op2==('+'||'-'))
        return(TRUE);
    if(op1==('+'||'-')&&op2==('*'||'/'))
        return(FALSE);
}
