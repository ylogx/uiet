/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 22, 2013
  *     Roll:       UE113090
  *     Program:    Access pointers of different classes using diff pointers
  **/
#include <iostream>
using namespace std;
 
  
class Base{
        int iv;
    public:
        void BaseInput(){
            cin>>iv;
        }
        void demo(){
            iv=0;
            cout<<"\nBase: demo= "<<iv;
        }
};
class Der1 : public Base{
        int i1;
    public:
        void Der1Input(){
            cin>>i1;
        }
        void demo(){
            i1=1;
            cout<<"\nDer1: demo= "<<i1;
        }
};
class Der2 : public Base{
        int i2;
    public:
        void Der2Input(){
            cin>>i2;
        }
        void demo(){
            i2=2;
            cout<<"\nDer2: demo= "<<i2;
        }
};

int main(){
    Base objb;
    Der1 obj1;
    Der2 obj2;
    cout<<"\n";
    objb.demo();
    obj1.demo();
    obj2.demo();
    Base* ptrb;
    //~ Der1* ptr1;
    //~ Der2* ptr2;

    ptrb=&objb;
    ptrb->demo();
    ptrb=&obj1;
    ptrb->demo();
    ptrb=&obj2;
    ptrb->demo();

    return 0;
}

/******************
Base: demo= 0
Der1: demo= 1
Der2: demo= 2

Base: demo= 0
Base: demo= 0
Base: demo= 0

------------------
(program exited with code: 0)
*******************/
