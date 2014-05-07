/*				DS Lab
	Shubham Chaudhary	UE 113090	CSE G5
Prob: WAP to insert, modify, delete, search elements in an array.
*/
#include<stdio.h>
//#include<stdlib.h>
#define LIMIT 3

//Global Variables
int arr[LIMIT];
int limit=LIMIT;

//Functions used in this program
void menu();
void insert();		/*functionn to insert at the end of array*/
void modify();		/*function to modify element at specified position*/
void delete();		/*to delete element at specified position*/
void search();		/*function to search input in array and output its position*/
void display();		/*function to print the array*/

void main()
{
  int i;
  printf("Enter array elements: ");
  for(i=0;i<limit;i++)
    scanf("%d",&arr[i]);
  menu();
}//main ends
void menu()
{
  int choice;		//choice for switch case
  printf("\n*** Enter ***\n1 to insert\n2 to delete\n3 to modify\n4 to search\n5 to escape\nChoice: ");
  scanf("%d",&choice);
  switch(choice)
    {
    case 1:
      insert();
      menu();
      break;
    case 2:
      delete();
      menu();
      break;
    case 3:
      modify();
      menu();
      break;
    case 4:
      search();
      menu();
      break;
    case 5:
      //exit fun
      break;
    default:
      printf("wish you knew how to count\n");
      menu();
    }//switch ends
}//menu ends
void delete()		/*to delete element at specified position*/
{
  int del_pos,i;
  printf("Enter position to be deleted: ");
  scanf("%d",&del_pos);
  /*a loop from del_pos-1 to end shifting each term by one on its way*/
  for(i=(del_pos-1);arr[i]!='\0';i++)	//arr starts from 0, therefore -1
    {
      arr[i]=arr[i+1];
    }
  limit-=1;	//helps display function
  display();
}//delete ends
void modify()		/*function to modify element at specified position*/
{
  int mod_pos;
  printf("Enter element to be modified: ");
  scanf("%d",&mod_pos);
  printf("Old Value: %d\nEnter new value: ",arr[mod_pos-1]);	//arr starts from 0
  scanf("%d",&arr[mod_pos-1]);
  display();
}
void search()		/*function to search input in array and output its position*/
{
  int i,s_term;
  printf("Enter search term (to find it's position in array): ");
  scanf("%d",&s_term);	//search term- input
  for(i=0;i<limit;i++)
    {
      if(arr[i]==s_term)		//if array element matches search term
	{
	  printf("Found @ : %d\n",i+1);	//position starts from 1, but arr starts from 0
	}//if
    }//for
}//search
void insert()		/*functionn to insert at the end of array*/
{
  display();
}
void display()		/*function to print the array*/
{
  int i;
  for(i=0;i<limit;i++)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
}
