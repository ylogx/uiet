/*
		DS Lab- 3
	   CSE Sec 2, Group 5
	      Aug 29, 2012
	       UE 113090
    Implementation of Queue using arrays
*/
#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
////////////////////Functions Used////////////////
//////////////////////////////////////////////////
void get_string();
//void put_string();
void push(int);
int pop();
int empty();
void check();
void display();

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
/*
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
*/
void check()
{
  int i,ele_poped,length;
  length=strlen(arr);
  printf("\nlength=%d, length/2=%d",length,length/2);  //for debugging
  display();  //for debugging
  for(i=0;i!=((length/2)-1);i++)
    {
      push(arr[i]);
      printf("\npushed %c",arr[i]);
      display();  //for debugging
    }
  for(i=(length/2);i!=length-1;i++)
    {
      ele_poped=pop();
      display();  //for debugging
      if(ele_poped!=arr[i])
	{
	  valid=FALSE;
	  printf("int invlaid if");  //for debugging
	}
    }
  if(!empty())  //if stack still contains an element it's not valid
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
  printf("Enter your string to check for ( [ { } ] ): \n");
  fflush(stdin);
  gets(arr);
}

//////////Display////////
void display()
{
  int i;
  printf("Stack is: \n");
  for(i=0;i!=top;i++)
    printf("%c\t",arr[i]);
  printf("\n");
}
