/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Jan 21, 2013
  *     Roll:   UE113090  
  *     Program:To Implement Array Operations in C++
  **/
#include<iostream>
using namespace std;
//***Global***
const int SIZE=115;
const int True=1;
const int False=0;
//*****Prototype*****
void insert(int*,int,int);
void display(int*);
void deletion(int *,int);
void modify(int*,int,int);
void linSearch(int *, int);
void bubbleSort(int*);
//****************
//******main******
int main(){
    int arr[SIZE]={23,34,78,56,67,78,89,78,'\0'};
    int choice;
    do{
        cout<<"\n1. Insert\n"
            <<"2. Delete\n"
            <<"3. Modify\n"
            <<"4. Display\n"
            <<"5. Search\n"
            <<"6. Bubble Sort\n"
            <<"7. Exit\n"
            <<"Enter Operation: ";
        cin>>choice;
        int loc,input,key;
        switch(choice){
            case 1:
                //int loc,input;
                cout<<"\nEnter location: ";
                cin>>loc;
                cout<<"\nEnter Data: ";
                cin>>input;
                insert(arr,loc,input);
                break;
            case 2:
                cout<<"\nEnter Location to delete: ";
                cin>>loc;
                deletion(arr,loc);
                break;
            case 3:
                cout<<"\nEnter value to modify <space> new value: ";
                cin>>key>>input;
                modify(arr,key,input);
                break;
            case 4: display(arr); break;
            case 5:
                cout<<"\nEnter data to search: ";
                cin>>key;
                linSearch(arr,key);
                break;
            case 6: bubbleSort(arr); break;
            case 7: break;
        }
    }while(choice!=7);

    //display(arr);
    //deletion(arr,7);
    //display(arr);
    return 0;
}
void display(int*ptr){     //To display the array
    cout<<"\nArray is: ";
    for(int i=0;ptr[i]!='\0';i++)
        cout<<ptr[i]<<'\t';
}
void deletion(int *ptr,int loc){     //To delete a specific location in array
    int i;
    for(i=loc;ptr[i]!='\0';i++){        //loc is index +1
        ptr[i-1]=ptr[i];
        //cout<<"deletion: "<<ptr[i]<<"goes to "<<ptr[i-1]<<endl;   //debug
    }
    ptr[i]='\0';
}
void insert(int *ptr,int loc,int input){     //To Insert at the given location in array
    int i,end;
    for(i=0;ptr[i]!='\0';i++);
    end=i;
    cout<<"\nEnd is: "<<end;
    for(i=end;i<loc;i--){
        ptr[i]=ptr[i-1];
    }
    ptr[loc-1]=input;
    display(ptr);
}
void modify(int* ptr,int key, int data){   //To modify a specific key with new data
    int loc;
    bool flag=False;
    for(loc=0;ptr[loc]!='\0';loc++){
        if(ptr[loc]==key){
            ptr[loc]=data;
            flag=True;
        }
    }
    if(!flag)
        cout<<"\nKey not found in Array";
}
void linSearch(int *ptr,int key){
    for(int i=0;ptr[i]!='\0';i++){
        if(ptr[i]==key){
            cout<<"\nKey "<<key<<" found at: "<<i+1<<'\n';
        }
    }
}
void bubbleSort(int*ptr){
    int i,j,temp;
    for(i=0;ptr[i]!='\0';i++){
        for(j=0;j<i;j++){
            if(ptr[j]<ptr[j+1]){
                temp=ptr[j];
                ptr[j]=ptr[i];
                ptr[i]=temp;
            }
        }
    }
}
                
/*
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 1

Enter location: 3

Enter Data: 464

End is: 8
Array is: 23    34  464 56  67  78  89  90  
1. Insert
2. Delete
3. Modify
4. Display
5. Exit
Enter Operation: 4

Array is: 23    34  464 56  67  78  89  90  

Enter Operation: 2

Enter Location to delete: 4

Enter Operation: 4

Array is: 23    34  464 67  78  89  90  90  

Enter Operation: 3

Enter value to modify <space> new value: 464 3464

Enter Operation: 4

Array is: 23    34  3464    67  78  89  90  90  

Enter Operation: 5


------------------
(program exited with code: 0)

1. Insert
2. Delete
3. Modify
4. Display
5. Search
6. Bubble Sort
7. Exit
Enter Operation: 4

Array is:   23  34  78  56  67  78  89  78  

Enter Operation: 5

Enter data to search: 78

Key 78 found at: 3

Key 78 found at: 6

Key 78 found at: 8

*/
