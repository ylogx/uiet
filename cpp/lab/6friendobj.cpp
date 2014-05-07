/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Mar 11, 2013
  *     Roll:   UE113090
  *     Program:Use of Friend Function and passing objects as reference
  **/ 
#include <iostream>
using namespace std;

class demo2;    //forward declaration

class demo1{
    private:
        int var1;
    public:
        void input(int in){ var1=in; }
        int output(){ return var1; }
        friend void copy(demo1 src1, demo2& des2 );     //reference of object 2
};
class demo2{
    private:
        int var2;
    public:
        void input(int in){ var2=in; }
        int output(){ return var2; }
        friend void copy(demo1 src1, demo2& des2 );
};

void copy(demo1 src1, demo2& des2 ){    //friend function
    des2.var2=src1.var1;
}

int main(){
    demo1 obj1;
    demo2 obj2;
    obj1.input(10);
    obj2.input(20);
    cout<<"var1 of obj1 is : "<<obj1.output()<<endl;
    cout<<"var2 of obj2 is : "<<obj2.output()<<endl;
    copy(obj1,obj2);    //NOTE reference of obj2 passed
    cout<<"--- Copied values from obj1 to obj2 ---"<<endl;
    cout<<"var1 of obj1 is : "<<obj1.output()<<endl;
    cout<<"var2 of obj2 is : "<<obj2.output()<<endl;
    return 0;
}
/********************************

var1 of obj1 is : 10
var2 of obj2 is : 20
--- Copied values from obj1 to obj2 ---
var1 of obj1 is : 10
var2 of obj2 is : 10


------------------
(program exited with code: 0)
Press return to continue

********************************/
