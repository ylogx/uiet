/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Mar 11, 2013
  *     Roll:   UE113090
  *     Program:Use of Constructor and destructor
  **/ 
#include <iostream>
const int SIZE = 20;
using namespace std;

class demo{
    private:
        char *array;
    public:
        demo(){ }    //empty constructor
        demo(char *);   //constructor # 2
        demo(int len, char * in);   //constructor # 3
        ~demo();
        void display(){
            //cout<<"\nInside display\n";
            cout<<"\nDISPLAY: Array is: "<<array;
            //cout<<"\nEnd display\n";
        }
};
demo::demo(char *in){
    cout<<"\nInside constructor # 2"<<endl;
    int i,lenIn=0;
    for(i=0;in[i]!='\0';i++)    //find length of input array
        lenIn+=1;
    //cout<<"done lenIn "<<lenIn;
    array=new char[lenIn+1];
    for(i=0;in[i]!='\0';i++){
        array[i]=in[i];
    }
    array[i]='\0';
    cout<<"array is "<<array<<endl;
}

demo::demo(int len, char * in){
    cout<<"\nInside constructor # 3"<<endl;
    int i;
    array=new char[len+1];
    for(i=0;i<len;i++){
        array[i]=in[i];
        //cout<<"copied "<<array[i]<<endl;
    }
    array[i]='\0';
    cout<<"array is "<<array<<endl;
}

demo::~demo(){
    cout<<"\nDest called";
    delete [] array;
}
int main(){
    //demo obj1;
    char arr[12]="12345678901";
    demo obj2(arr);
    demo obj3(5,arr);
    cout<<"\n-------------------"<<endl;
    obj2.display();
    obj3.display();
    cout<<"\n-------------------"<<endl;
    return 0;
}

/*********************************
**************OUTPUT**************
==3819== Memcheck, a memory error detector
==3819== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==3819== Command: ./6constDest.out
==3819== 

Inside constructor # 2
array is 12345678901

Inside constructor # 3
array is 12345

-------------------

DISPLAY: Array is: 12345678901
DISPLAY: Array is: 12345
-------------------

Dest called
Dest called
==3819== 
==3819== HEAP SUMMARY:
==3819==     in use at exit: 0 bytes in 0 blocks
==3819==   total heap usage: 2 allocs, 2 frees, 18 bytes allocated
==3819== 
==3819== All heap blocks were freed -- no leaks are possible
==3819== 
==3819== For counts of detected and suppressed errors, rerun with: -v
==3819== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
*****************************************************/
