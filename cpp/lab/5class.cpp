/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Feb 11, 2013
  *     Roll:   UE113090
  *     Program:To create class as explained in problem
  **/
#include<iostream>
using namespace std;
//*****Class Declaration*****
class No1{
    private:
    public:
        int var1,var2,var3;
};
class No2{
    private:
        int a,b,c;
    public:
        void inA(int in){a=in;}
        int outA(){return a;}
        void inB(int in){ b=in;}
        int outB(){return b;}
        void inC(int in){ c= in; }
        int outC(){return c; }
};
class No3{
    private:
        int a,b,c;
        void inA(int in){a=in;}
        int outA(){return a;}
        void inB(int in){ b=in;}
        int outB(){return b;}
        void inC(int in){ c= in; }
        int outC(){return c; }
    public:
        void initA0(){ inA(0); cout<<"\na= "<<outA(); }
        void initB0(){ inB(0); cout<<"\na= "<<outB(); }
        void initC0(){ inC(0); cout<<"\na= "<<outC(); }
};
//******main******
int main(){
    No1 instance1;
    No2 instance2;
    instance1.var1=0;
    instance1.var2=1;
    instance1.var3=123456;
    cout<<"\nvar1= "<<instance1.var1;
    cout<<"\nvar2= "<<instance1.var2;
    cout<<"\nvar3= "<<instance1.var3;
    instance2.inA(989);
    instance2.inB(1234);
    instance2.inC(263);
    cout<<"\na= "<<instance2.outA();
    cout<<"\nb= "<<instance2.outB();
    cout<<"\nc= "<<instance2.outC();
    No3 instance3;
    instance3.initA0();
    instance3.initB0();
    instance3.initC0();
    return 0;
}
/*var1= 0
var2= 1
var3= 123456
a= 989
b= 1234
c= 263
a= 0
a= 0
a= 0
*************************/
