/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Mar 18, 2013
  *     Roll:       UE113090
  *     Program:    Overload operator * for class*const & const*class.
  **/
#include <iostream>
using namespace std;

class eval {
    private:
        int var;
    public:
        eval(){ }   //empty
        eval(int in){ var=in; }
        void input(int in){ var = in; }
        int output(){ return var; }
        eval operator *( int );
        friend eval operator *(int,eval);
};
eval eval:: operator *(int in) {
    eval temp;
    temp=*this;
    var=var*in;
    temp = *this;
    var= var / in;
    return temp;
}
/*
eval int::operator *(eval in){
    eval temp;
    temp.input(in.output() * *this);
    return temp;
}
*/
eval operator *(int in1,eval in2){  //friend function used to overload operator
    eval temp;
    temp.var = in1 * in2.var;
    return temp;
}
int main(){
    eval a(10),b;
    b.input(30);
    cout<<"\n a var = "<<a.output();
    cout<<"\n b var = "<<b.output();
    a=b*26;     //call overloaded operator * function
    cout<<"\n a var = "<<a.output();
    cout<<"\n b var = "<<b.output();
    a=11*b;     //call friend function for overloading
    cout<<"\n a var = "<<a.output();
    cout<<"\n b var = "<<b.output();
    return 0;
}
/**********************************************
 a var = 10
 b var = 30
 a var = 780
 b var = 30
 a var = 330
 b var = 30

------------------
(program exited with code: 0)
Press return to continue
************************************************/
