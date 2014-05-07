/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Jan 28, 2013
  *     Roll:   UE113090  
  *     Program:To Implement searching and sorting in Linked List using C++
  **/
#include<iostream>
using namespace std;
//*****Strcture*******
struct nodeS{
    int info;
    nodeS *next;    //points to the next link
    int index;
};
//typedef struct nodeS * nodePtr;
//*****Prototype*****
void freeMem(nodeS*);
void insert(nodeS*,int);
void display(nodeS*);
void del(nodeS*,int);
void modify(nodeS*,int,int);
void linSearch(nodeS*,int);
void bubbleSort(nodeS*);
void binSearch(nodeS*,int);
void binSearchIn(nodeS*start,int key);
int locate(nodeS* list,int loc);
int locateIn(nodeS* list,int loc);
//****************
//******main******
int main(){
    nodeS* list=new nodeS;
    list->next=NULL;
    list->info=0;
    list->index=0;
    int choice;
        cout<<"\n0. Exit\n"
            <<"1. Insert\n"
            <<"2. Delete\n"
            <<"3. Modify\n"
            <<"4. Display\n"
            <<"5. Linear Search\n"
            <<"6. Bubble Sort\n"
            <<"7. Binary Search\n"
            <<"8. Binary Search Using index\n"
            <<"Enter Operation: ";
    do{
        cin>>choice;
        switch(choice){
            int input,data,key;
            case 0: freeMem(list); break;
            case 1: cout<<"\nEnter Data: "; cin>>input; insert(list,input); break;
            case 2: cout<<"\nEnter Data: "; cin>>data; del(list,data); break;
            case 3:
                cout<<"\nEnter value to modify and new value: ";
                cin>>key>>input;
                modify(list,key,input);
                break;
            case 4: display(list); break;
            case 5: 
                cout<<"\nEnter Key: ";
                cin>>key;
                linSearch(list,key);
                break;
            case 6:
                bubbleSort(list);
                break;
            case 7: 
                cout<<"\nEnter Key: ";
                cin>>key;
                binSearch(list,key);
                break;
            case 8:
                cout<<"\nEnter Key: ";
                cin>>key;
                binSearchIn(list,key);
                break;
            case 9:
                cout<<"\nEnter location for locate function: ";
                cin>>input;
                cout<<"\nOutput of locate(list,input): "<<locateIn(list,input);
                break;
        }
        cout<<"\nEnter Operation: ";
    }while(choice);
    //delete list;
    return 0;
}
void insert(nodeS* list,int data){     //To Insert at the end of linked list
    nodeS* temp=new nodeS ;
    for(int i=0;list->next!=NULL;i++)   //traverse to the end
        list=list->next;
    list->next=temp;    //point to temp instead of NULL
    temp->info=data;
    temp->next=NULL;
    temp->index=list->index +1;
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
void freeMem(nodeS* ptr){
    nodeS *temp=ptr;
    for(int i=0;ptr->next!=NULL;i++){
        temp=ptr;
        ptr=ptr->next;
        delete temp;
    }
    //delete temp;
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
        cout<<"\nList is: \n";
        for(int i=0;list!=NULL;i++){
            cout<<list->index<<':'<<list->info<<'\t';
            list=list->next;
        }
    }
}
void linSearch(nodeS*ptr,int key){
    for(int i=0;ptr->next!=NULL;i++){
        if(ptr->info==key){
            cout<<"\nKey "<<key<<" found @: "<<i<<"th link\n";
        }
        ptr=ptr->next;
    }
}
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
void binSearch(nodeS*start,int key){
    //bubbleSort(start);
    cout<<"\nBubble Sort done !";
    nodeS* ptr;
    ptr=start;
    int i,length=0;
    for(i=0;ptr->next->next!=NULL;i++){
        length+=1;
        ptr=ptr->next;
        cout<<"\nlooping in bin search. length: "<<ptr->info;
    }
    cout<<"\nOut in binSearch fun.";
    float mid;
    int lo,hi;
    lo=0;
    hi=length+1;
    while (1){
        //cout<<"\nInside While 1";
        mid=(lo+hi)/2;
        cout<<"\nWhile: mid: "<<mid<<" length: "<<length<<" locate ptr mid= "<<locate(ptr,mid)<<" Key= "<<key;
        if(mid<=0 || mid>length){
            cout<<"\nIterative Binary Search: "<<key<<" Not Found";
            break;
        }
        else if(locate(start,int(mid))==key){
            cout<<"\nIterative Binary Search: "<<key<<" found at position "<<((int)mid+1)<<'\n';
            break;
        }
        else if(locate(start,int(mid))<key){
            lo=mid+1;
        }
        else{    //a[mid]>key
            hi=mid-1;
        }
    }//end while
}
int locate(nodeS* list,int loc){    //locate item at location 'loc'
    list=list->next;    //header
    for(int i=0;i<loc;i++){
        if(list->next==NULL)
            break;
        else
            list=list->next;
    }
    return list->info;
}
void binSearchIn(nodeS*start,int key){
    //bubbleSort(start);
    //display(start);
    cout<<"\nBubble Sort done !";
    nodeS* ptr;
    ptr=start;
    int i,length=0;
    for(i=0;ptr->next->next!=NULL;i++){
        length+=1;
        ptr=ptr->next;
        cout<<"\nlooping in bin search. length: "<<ptr->info;
    }
    cout<<"\nOut in binSearch fun.";
    float mid;
    int lo,hi;
    lo=1;
    hi=length+1;
    while (1){
        //cout<<"\nInside While 1";
        mid=(lo+hi)/2;
        cout<<"\nWhile: mid: "<<mid<<" length: "<<length<<" locate ptr mid= "<<locate(ptr,mid)<<" Key= "<<key;
        if(mid<=0 || mid>length){
            cout<<"\nIterative Binary Search: "<<key<<" Not Found";
            break;
        }
        else if(locateIn(start,int(mid))==key){
            cout<<"\nItrBinSrch: "<<key<<" found at position "<<(int)mid<<'\n';
            break;
        }
        else if(locateIn(start,int(mid))<key){
            lo=mid+1;
        }
        else{    //a[mid]>key
            hi=mid-1;
        }
    }//end while
}
int locateIn(nodeS* list,int loc){    //locate item at location 'loc'
    list=list->next;    //header
    for(int i=0;list->index!=loc;i++){
        if(list->next==NULL)
            return 0;
        else
            list=list->next;
    }
    return list->info;
}


/* * * * * * * * * * O U T P U T * * * * * * * * * *

Script started on Monday 04 February 2013 01:28:17 AM IST

chaudhary@Dell-XPS-L502XC:~/code/cpp$ time valgrind --leak-check=full ./1130903.out
 * * * G++: Compiling 1130903.cpp file * * *

 * * * Valgrind Test: 1130903.test found * * *
==14170== Memcheck, a memory error detector
==14170== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14170== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14170== Command: ./1130903.out
==14170== 

0. Exit
1. Insert
2. Delete
3. Modify
4. Display
5. Linear Search
6. Bubble Sort
7. Binary Search
8. Binary Search Using index

Enter Operation: 1 56 1 23 1 48 1 12 1 34 1 9 1 3 1 -3 1 -12
Enter Operation: 4
List is: 1:56	2:23	3:48	4:12	5:34	6:9	7:3	8:-3	9:-12	

Enter Operation: 3
Enter value to modify and new value: 34 96
Enter Operation: 4
List is: 1:56	2:23	3:48	4:12	5:96	6:9	7:3	8:-3	9:-12	

Enter Operation: 5
Enter Key: -3
Key -3 found @: 8th link

Enter Operation: 4
List is:  1:56	2:23	3:48	4:12	5:96	6:9	7:3	8:-3	9:-12
Enter Operation: 6
Enter Operation: 4
List is: 1:-12	2:-3	3:3	4:9	5:12	6:23	7:48	8:56	9:96	

Enter Operation: 7
Enter Key: 48
looping in bin search. length: -12
looping in bin search. length: -3
looping in bin search. length: 3
looping in bin search. length: 9
looping in bin search. length: 12
looping in bin search. length: 23
looping in bin search. length: 48
looping in bin search. length: 56
Out in binSearch fun.
While: mid: 4 length: 8 locate ptr mid= 96 Key= 48
While: mid: 7 length: 8 locate ptr mid= 96 Key= 48
While: mid: 5 length: 8 locate ptr mid= 96 Key= 48
While: mid: 6 length: 8 locate ptr mid= 96 Key= 48
Iterative Binary Search: 48 found at position 7

Enter Operation: 7
Enter Key: 96
looping in bin search. length: -12
looping in bin search. length: -3
looping in bin search. length: 3
looping in bin search. length: 9
looping in bin search. length: 12
looping in bin search. length: 23
looping in bin search. length: 48
looping in bin search. length: 56
Out in binSearch fun.
While: mid: 4 length: 8 locate ptr mid= 96 Key= 96
While: mid: 7 length: 8 locate ptr mid= 96 Key= 96
While: mid: 8 length: 8 locate ptr mid= 96 Key= 96
Iterative Binary Search: 96 found at position 9

Enter Operation: 7
Enter Key: -3
looping in bin search. length: -12
looping in bin search. length: -3
looping in bin search. length: 3
looping in bin search. length: 9
looping in bin search. length: 12
looping in bin search. length: 23
looping in bin search. length: 48
looping in bin search. length: 56
Out in binSearch fun.
While: mid: 4 length: 8 locate ptr mid= 96 Key= -3
While: mid: 1 length: 8 locate ptr mid= 96 Key= -3
Iterative Binary Search: -3 found at position 2

Enter Operation: 0
------------------
(program exited with code: 0)
==14170== 
==14170== HEAP SUMMARY:
==14170==     in use at exit: 24 bytes in 1 blocks
==14170==   total heap usage: 10 allocs, 9 frees, 240 bytes allocated
==14170== 
==14170== 24 bytes in 1 blocks are definitely lost in loss record 1 of 1
==14170==    at 0x4C2B1C7: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14170==    by 0x401084: insert(nodeS*, int) (1130903.cpp:90)
==14170==    by 0x400EDF: main (1130903.cpp:52)
==14170== 
==14170== LEAK SUMMARY:
==14170==    definitely lost: 24 bytes in 1 blocks
==14170==    indirectly lost: 0 bytes in 0 blocks
==14170==      possibly lost: 0 bytes in 0 blocks
==14170==    still reachable: 0 bytes in 0 blocks
==14170==         suppressed: 0 bytes in 0 blocks
==14170== 
==14170== For counts of detected and suppressed errors, rerun with: -v
==14170== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 2 from 2)

   * * * Done * * * 

real	0m0.727s
user	0m0.628s
sys		0m0.080s


chaudhary@Dell-XPS-L502XC:~/code/cpp$ exit
Script done on Monday 04 February 2013 01:30:22 AM IST

* * * * * * * * * * * * * * * * * * * * * * * * * * * */
