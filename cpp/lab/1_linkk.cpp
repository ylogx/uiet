// AIM: WAP to create a linked list and perform insertion, deletion and modify elements in that list.
#include<iostream>
//#include<conio.h>
#include<stdlib.h>
using namespace std;
struct list
{
  int info;                                                                      
  struct list *next;
};
typedef struct list node;
node *head;
void insertbeg()
{
  node *temp;
  temp=new node;
  cout<<"enter data";
cin>>temp->info;
 if(head==NULL)
   {
     temp->next=NULL;
head=temp;
   }
 else
   {
     temp->next=head;
     head=temp;
   }
 return;
}
void insertend()
{
  node *temp,*ptr;
  temp=new node;
  ptr=new node;
  cout<<"enter data";
  cin>>temp->info;
  if(head==NULL)
    {
      temp->next=NULL;
      head=temp;
}
  else
    {
      ptr=head;
      while(ptr->next!=NULL)
    {
ptr=ptr->next;
    }
      ptr->next=temp;
      temp->next=NULL;
    }
  return;
}
void insertmid()
{
  node *temp,*ptr1,*ptr2;
  int x;
temp=new node;
 if(head==NULL)
   {
     cout<<"empty";
     return;
}
 cout<<"enter data before which to insert";
 cin>>x;
 if(x==head->info)
   {
     insertbeg();
return;
   }
 ptr2=head;
 ptr1=head->next;
 while(ptr1!=NULL&&ptr1->info!=x)
   {
     ptr2=ptr1;
ptr1=ptr1->next;
   }
 if(ptr1==NULL)
   {
     cout<<"data doesnot exist";
}
 else
   {
     cout<<"enter data";
     cin>>temp->info;
     ptr2->next=temp;
     temp->next=ptr1;
}
 return;
}
void deletion()
{
  node *pt,*t;
  int x;
  if(head==NULL)
    {
cout<<"empty";
 return;
    }
  cout<<"enter data to be deleted";
  cin>>x;
if(x==head->info)
  {
    t=head;
    head=head->next;
free(t);
 cout<<x<<"is deleted";
 return;
  }
 pt=head;
 t=head->next;
while(t!=NULL&&t->info!=x)
  {
    pt=t;
    t=t->next;
  }
if(t==NULL)
  {
    cout<<"does not exist";
    return;
  }
 else
{
  pt->next=t->next;
 }
 cout<<x<<"is deleted";
 free(t);
 return;
}
void modify()
{
  node *t;
int x,y;
 cout<<"enter data to modify and modified value";
 cin>>x>>y;
 if(head==NULL)
{
  cout<<"empty";
  return;
 }
 else
   {
t=head;
 while(t!=NULL&&t->info!=x)
   {
     t=t->next;
   }
 t->info=y;
   }
}
void search()
{
  node *temp;
  int data;
cout<<"enter the data you want to search";
 cin>>data;
 if(head==NULL)
   {
     cout<<"empty";
     return;
}
 temp=head;
 while(temp!=NULL)
   {
     if(temp->info==data)
       {
     cout<<"element found";
break;
       }
     temp=temp->next;
   }
 if(temp==NULL)
   cout<<"element not found";
 return;
}
void sort()
{
  node *temp,*ptr;
  int n=0,i,j,data;
  temp=head;
  while(temp!=NULL)
  {
    n++;
    temp=temp->next;
  }
  cout<<n;
  temp=head;
  ptr=head->next;
  for(i=0;i<=n-1;i++)
  {
    for(j=0;j<=n-1-i;j++)
    {
      cout<<"\nComparing (temp->info) > (ptr->info)"<<(temp->info) <<" > " <<(ptr->info);
      if((temp->info) > (ptr->info))
        {
            data= ptr->info;
            ptr->info=temp->info;
            temp->info=data;
        }
      cout<<"ptr value"<<ptr->info<<"\t temp value"<<temp->info<<endl;  //getch();
      temp=ptr;
      ptr=ptr->next;
    }
    temp=head;
    ptr=head->next;
 }
 /*     for(i=0;i<n;i++)
        {
        min=temp->info;
        for(j=i+1;j<n;j++)
        {
        if(ptr->info < min)
        min=ptr->info;
        ptr=ptr->next;
        }
         data=min;
         min=temp->info;
         temp->info=data;
         
         temp=temp->next;
         }*/
 return;
}
void display()
{
  node *temp;
  if(head==NULL)
{
  cout<<"empty";
  return;
 }
  cout<<"\nelements are\n";
  temp=head;
while(temp!=NULL)
  {
    cout<<"\n"<<temp->info;
    temp=temp->next;
  }
 return;
}
int main()
{
  int a,c;
  //clrscr();
  head=NULL;
do
  {
    cout<<"\n1:insert\n2:delete\n3:display\n4:modify\n5:search\n6:sort\n7:exit\nenter the choice";
    cin>>c;
    switch(c)
      {
      case 1:
    {
      cout<<"\n1:insert at beginning\n2:insert at end\n3:insert in mid\nenter the choice";
      cin>>a;
      switch(a)
        {
        case 1:
{
  insertbeg();
  break;
 }
        case 2:
{
  insertend();
  break;
 }
case 3:
  {
    insertmid();
    break;
}
        }
      break;
    }
      case 2:
    {
deletion();
 break;
    }
      case 3:
    {
      display();
break;
    }
      case 4:
    {
modify();
 break;
    }
      case 5:
    {
      search();
      break;
}
      case 6:
    {
      sort();
      break;
    }
case 7:
  {
    exit(0);
    break;
  }
      default:
cout<<"try again";
      }
  } while(c!=7);
 return 0;
}
//1 2 56 1 2 23 1 2 48 1 2 12 1 2 34 1 2 9 1 2 3 1 2 -3 1 2 -12
void bubbleSort(nodeS* ptr){
    nodeS* start;
    start=ptr->next;    //we don't want to compare header's info
    int i,j,length=0;
    for(i=0;ptr->next!=NULL;i++){
        length+=1;
        ptr=ptr->next;
        //cout<<"\nlooping in bubbleSort. length: "<<length;
    }
    //cout<<"\nOut in bubbleSort fun.";
    ptr=start;
    for(i=0;i<length;i++){
        for(j=1;j<length-i;j++){
            //cout<<"\nComparing: "<<ptr->info<<" and "<<ptr->next->info;
            if(ptr->info>ptr->next->info){  //move bigger down
                int temp=ptr->info;
                ptr->info=ptr->next->info;
                ptr->next->info=temp;
            }
            ptr=ptr->next;
        }
        ptr=start;
    }
}
