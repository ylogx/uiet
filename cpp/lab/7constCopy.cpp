/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Mar 18, 2013
  *     Roll:       UE113090
  *     Program:    Copy Constructor
  **/
#include <iostream>
using namespace std;
class demo;
class demo{
    private:
        int var;
    public:
        void input(){ cin>>var; }
        void output(){ cout<<var; }
        demo(int in){ var=in; }
        demo(demo&); //copy constructor
};
/*
 *  Q.  Why must a copy constructor be passed its parameter by reference?
 *  A.  Because if it's not by reference, it's by value. To do that you make a copy, 
 *      and to do that you call the copy constructor. But to do that, 
 *      we need to make a new value, so we call the copy constructor, and so on...
 *      (You would have infinite recursion because "to make a copy, you need to make a copy".)
 *      Also known as Circular Dependencies.
 */
demo::demo(demo& in){
    var=in.var;
}
int main(){
    demo a(10);
    cout<<"\na var: ";
    a.output();
    demo b(a);  //calls copy constructor
    cout<<"\nAfter demo b(a)\nb var: ";
    b.output();
    return 0;
}
/****************************************
a var: 10
After demo b(a)
b var: 10

------------------
(program exited with code: 0)
Press return to continue
*****************************************/
