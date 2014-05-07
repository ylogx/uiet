#include<stdio.h>



//*****************Global Variables***************
#define STACKSIZE 100
struct stack 
{
  int top;
  int items[STACKSIZE];
};//there is another way to declare stack struct with no restriction of data type: refer page 87

#define TRUE 1
#define FALSE 0

//*******************Functions Used***************
void push();
int pop();
int empty(struct stack *);

void main()
{
  struct stack s;
}

//**********EMPTY************
int empty(struct stack *ps)
{
  if(ps->top==-1)
  return(TRUE);
  else
  return(FALSE);
  //return(ps->top==(-1));  //this statement can also be used in place of all these statements
}

//**************POP*************
int pop(struct stack *ps)
{
  if (empty(ps))
  {
    printf("%s","Stack UNDERFLOW");
    exit(1);
  }//end if
  return(ps->items[ps->top--]);
}//end pop
