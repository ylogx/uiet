/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Mar 11, 2013
  *     Roll:   UE113090
  *     Program:Use of Friend Function
  **/ 
#include <iostream>
using namespace std;

class demo2;    //forward declaration
class demo3;    //forward declaration

class demo1{
    private:
        int var1;
    public:
        void input(int in){ var1=in; }
        friend void display(demo1 obj1, demo2 obj2, demo3 obj3);
};
class demo2{
    private:
        int var2;
    public:
        void input(int in){ var2=in; }
        friend void display(demo1 obj1, demo2 obj2, demo3 obj3);
};
class demo3{
    private:
        int var3;
    public:
        void input(int in){ var3=in; }
        friend void display(demo1 obj1, demo2 obj2, demo3 obj3);
};

void display(demo1 obj1, demo2 obj2, demo3 obj3){   //friend function
    cout<<"Var1 is : "<<obj1.var1<<endl;
    cout<<"Var2 is : "<<obj2.var2<<endl;
    cout<<"Var3 is : "<<obj3.var3<<endl;
}

int main(){
    demo1 obj1;
    demo2 obj2;
    demo3 obj3;
    obj1.input(10);
    obj2.input(20);
    obj3.input(30);
    display(obj1,obj2,obj3);
    return 0;
}

/*******************

Var1 is : 10
Var2 is : 20
Var3 is : 30


------------------
(program exited with code: 0)
Press return to continue

********************/
