/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Jan 14, 2013
  *     Roll:   UE113090  
  *     Program:To Implement Linked List in C++
  **/
#include<iostream>
using namespace std;
//*****Strcture*******
struct nodeS{
    int info;
    nodeS *next;    //points to the next link
};
//typedef struct nodeS * nodePtr;
//*****Prototype*****
void insert(nodeS*,int);
void display(nodeS*);
void del(nodeS*,int);
void modify(nodeS*,int,int);
//****************
//******main******
int main(){
    nodeS* list=new nodeS;
    list->next=NULL;
    list->info=0;
    int choice;
    do{
        cout<<"\n1. Insert\n"
            <<"2. Delete\n"
            <<"3. Modify\n"
            <<"4. Display\n"
            <<"5. Exit\n"
            <<"Enter Operation: ";
        cin>>choice;
        switch(choice){
            case 1: int input; cout<<"\nEnter Data: "; cin>>input; insert(list,input); break;
            case 2: int data; cout<<"\nEnter Data: "; cin>>data; del(list,data); break;
            case 3:
                int key,mod;
                cout<<"\nEnter value to modify and new value: ";
                cin>>key>>mod;
                modify(list,key,mod);
                break;
            case 4: display(list); break;
            case 5: break;
        }
    }while(choice!=5);
    return 0;
}
void insert(nodeS* list,int data){     //To Insert at the end of linked list
    nodeS* temp=new nodeS ;
    for(int i=0;list->next!=NULL;i++)   //traverse to the end
        list=list->next;
    list->next=temp;
    temp->info=data;
    temp->next=NULL;
}
void del(nodeS* list,int key){     //To delete a specific key from linked list
    if (list->next==NULL)
        cout<<"\nList is Empty";
    else{
        for(int i=0;list->next->info!=key;i++){
            list=list->next;
        }
        nodeS* temp=list->next;
        list->next=list->next->next;
        delete temp;
    }
}
void modify(nodeS* list, int key, int data){   //To modify a specific key with new data
    list=list->next;    //don't print header
    for(int i=0;list->info!=key;i++)
        list=list->next;
    list->info=data;
}
void display(nodeS* list){     //To display the linked list
    list=list->next;    //don't print header
    if (list==NULL)
        cout<<"\nList is Empty";
    else{
        for(int i=0;list!=NULL;i++){
            cout<<list->info<<'\t';
            list=list->next;
        }
    }
}
/*  OUTPUT
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 1 12 1 23 1 34 1 45 1 56

Enter Data: 
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 4
12  23  34  45  56  
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 2

Enter Data: 45

1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 4
12  23  34  56  
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 3

Enter value to modify and new value: 23
2013

1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 4
12  2013    34  56  
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
*/
