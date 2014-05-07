#include<stdio.h>
#include<conio.h>
//---------------------------------------
//-------------Functions Used------------
//---------------------------------------
void push();
void pop();
void menu();
void display_stack();
#define SIZE 5
//-----------Global Variables-----------
int stack[SIZE],top=(-1),ele_pushed,ele_poped;

//---------------------------------------
//------------Main Function--------------
//---------------------------------------
void main()
{
  clrscr();
  menu();
  display_stack();
  getch();
}
//----------------------------------------
//--------------Push Function-------------
//----------------------------------------
void push()
{
  if(top==SIZE)	//stack full
    printf("\nStack is full, can't push");
  else
    {
      printf("\nEnter element to be pushed: ");
      scanf("%d",&ele_pushed);
stack[top]=ele_pushed;
 top=top+1;
 printf("\nSuccess:\n%d pushed in stack",ele_pushed);
 display_stack();
 menu();
}//else ends
}
//----------------------------------------
//--------------Pop Function--------------
//----------------------------------------
void pop()
{
if(top==(-1)) 	//stack empty
  printf("\nStack is already empty, can't Pop");
 else
   {
     ele_poped=stack[top-1];
top=top-1;
 printf("\nSuccess:\n%d poped",ele_poped);
 display_stack();
 menu();
   }//else ends
}

//----------------------------------------
//--------------MENU----------------------
//----------------------------------------
void menu()
{
int choice;
 printf("\n---Enter---\n1 to Push\n2 to Pop\n3 to exit");
 scanf("%d",&choice);
 switch(choice)
   {
case 1:
  push();
  break;
   case 2:
     pop();
printf("\nElement poped: %d",ele_poped);
 break;
   default:
     printf("\nWish you knew how to count\n");
menu();
   }//switch ends
}
//----------------------------------------
//--------------Display Function----------
//----------------------------------------
void display_stack()
{
int i;
 printf("\n---------------Stack-----------------\n");
 for(i=0;i!=top;i++)
   {
printf("%d\t",stack[i]);
   }
 printf("\n--------------------------------------");
}


