#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
void main()
{
  int top,i,ch;
  char a[10];
  //clrscr();
  printf("enter value of top");
  scanf("%d",&top);
  printf("top=%d\nenter character",top);
  for(i=0;i<=top;i++)
    scanf("%c",&a[i]);
  while(1)
    {
      printf("press 1 to PUSH \n press 2 to POP\n3 to exit");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:
	  {
	    if(top==10)
	      printf("stack is full");
	    else
	      {
		top=top+1;
		printf("enter character to push");
		scanf("%c",&a[top]);
		printf("\nstack is:");
		for(i=0;i<=top;i++)
		  printf("%c",a[i]);
	      }
	    break;
	  }
	case 2:
	  {
	    if(top==0)
	      printf("stack is empty");
	    else
	      {
		top=top-1;
		printf("stack is:");
		for(i=0;i<=top;i++)
		  printf("%c",a[i]);
	      }
	    break;
	  }
	case 3:
	  exit(0);
	}
    }
  //getch();
}
