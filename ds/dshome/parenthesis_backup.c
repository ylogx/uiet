/*
Shubham Chaudhary
A program to check validity of parenthesis of an expression
*/
#include<stdio.h>
//////////////////////////////////////////////////
////////////////////Functions Used////////////////
//////////////////////////////////////////////////
void get_string();
void put_string();
void push(int);
int pop();
int empty();
void check();

/////////////////////////////////////////////////
////////////Global Variables/////////////////////
/////////////////////////////////////////////////
char arr[100];
int top,valid;

#define TRUE (1)
#define FALSE (0)

///////////////Main Function/////////////////////
void main()
{
  valid=TRUE;//assume string is valid
  get_string();
  check();
  if (valid)
    printf("valid string\n");
  else
    printf("invalid string\n");
}

//////////Check Function//////////////////////////
void check()
{
  int i,ele_poped;
  for(i=0;arr[i]!='\0';i++)
    {
      if(arr[i]=='(' || arr[i]=='[' || arr[i]=='{')
	{
	  push(arr[i]);
	  printf("pushed %d\n",arr[i]);
	}
      else if(arr[i]==')' || arr[i]==']' || arr[i]=='}')
	{
	  if(empty())
	    valid=FALSE;//there is a closing bracket and stack is empty
	  else
	    {
	      ele_poped=pop();
	      if(ele_poped!=arr[i])
		valid=FALSE; //parenthesis that was open must be closed before adding new one
	    }
	}
    }
  if(!empty())
    valid=FALSE;
}

////////////////Empty///////////////////
int empty()
{
  if(top==0)
    return(1);//TRUE- empty
  else
    return(0);//FALSE- not empty
}

//*************PUSH*********************
void push(int ele_pushed)
{
  //int ele_pushed;
  //printf("Enter ele to be pushed: ");
  //scanf("%d",&ele_pushed);
  arr[top]=ele_pushed;
  top+=1; //top=top+1
}

//**************POP**********************
int pop()
{
  if(empty()==1)
    printf("Stack is empty ! ! !\n");
  else if (empty()==0)
    {
      top=top-1;
    }
  return (arr[top+1]);
}

//////////////Get String///////////////
void get_string()
{
  printf("Enter yor string to check for ( [ { } ] ): \n");
  gets(arr);
}
