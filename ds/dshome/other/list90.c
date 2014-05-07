/*DS LAB-3
CSE-SEC2,GROUP 5
UE113090
DATE: OCTOBER 3,2012
  		          	
*/
// AIM: WAP to create a linked list and then insert or delete elements in that linked list.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
int info;                                                                      // structure of a node
struct list *next;
};
void main()
{
typedef struct list node;
node *ptr,*temp;
node *head=NULL;                                                      //declaring the nodes
int i,k,data,ch,a,no;
clrscr();
printf("enter the number of nodes of a linked list");
scanf("%d",&k);
temp=(node*)malloc(sizeof(node));                   //allocating memory to a node
printf("enter the data of 1 node");
scanf("%d",&data);                                         //input data of the node
temp->info=data;
temp->next=head;
head=temp;
for(i=2;i<=k;i++)
{
ptr=(node*)malloc(sizeof(node));                          //temporary node
printf("enter the data of %d node",i);
scanf("%d",&data);
ptr->info=data;
temp->next=ptr;                                               //creating a linked list
temp=temp->next;
}
temp->next=NULL;
printf("the list is\n");
temp=head;
while(temp!=NULL)                                         //printing a linked list
{
data=temp->info;
printf("%d\n",data);
temp=temp->next;
}
printf("enter 1 to insert\nenter 2 to delete");
scanf("%d",&ch);
switch(ch)                                           //switch case for insertion or deletion
{
case 1:
{
node *ins;                                                  //node to be inserted
ins=(node*)malloc(sizeof(node));
printf("enter 1 to insert at beg\n2 to insert in mid\n3 to insert at last");
scanf("%d",&a);
printf("enter the data to insert");
scanf("%d",&data);
ins->info=data;
if(a==1)
{                                                                  //inserting at beginning
ins->next=head;
head=ins;
}
if(a==2)
{
temp=head;                                               //inserting after specified node
printf("enter the node number after which to insert");
scanf("%d",&no);
for(i=1;i<=no;i++)
{
ptr=temp;
temp=temp->next;
}
ptr->next=ins;
ins->next=temp;
}
if(a==3)
{
temp=head;                                             //inserting at end
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ins;
ins->next=NULL;
}
break;
}
case 2:
{
printf("enter 1 to delete from beg\n2 to delete from mid\n3 to delete from end");
scanf("%d",&a);
if(a==1)
{                                                               //deleting from beginning
temp=head;
temp=temp->next;
head=temp;
}
if(a==2)
{
temp=head;                                            //deleting a specified node
printf("enter the node number to delete");
scanf("%d",&no);
for(i=1;i<no;i++)
{
ptr=temp;
temp=temp->next;
}
ptr->next=temp->next;
}
if(a==3)
{                                                            //deleting the last node
temp=head;
while(temp->next!=NULL)
{
ptr=temp;
temp=temp->next;
}
ptr->next=NULL;
}
break;
}
default:
printf("error");
}
printf("\nthe list is\n");
temp=head;
while(temp!=NULL)
{                                                //printing the list after inserting or deleting
data=temp->info;
printf("%d\n",data);
temp=temp->next;
}
getch();
}
 
