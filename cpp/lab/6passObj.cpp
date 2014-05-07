/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Mar 11, 2013
  *     Roll:   UE113090
  *     Program:Passing object to member function
  **/ 
#include <iostream>
using namespace std;

class pass{
    private:
        int a,b;
    public:
        void input(int,int);
        int aDiff(pass);
        int bDiff(pass);
};
inline void pass::input(int input1, int input2){
    a=input1;
    b=input2;
}
inline int pass::aDiff(pass objIn){
    return ( a - objIn.a );
}
inline int pass::bDiff(pass objIn){
    return ( b - objIn.b );
}
int main(){
    pass obj1,obj2;
    int temp1,temp2;
    cout<<"Input a b for obj1: ";
    cin>>temp1>>temp2;
    obj1.input(temp1,temp2);
    cout<<"Input a b for obj2: ";
    cin>>temp1>>temp2;
    obj2.input(temp1,temp2);
    cout<<"Difference b/w value of obj1.a - obj2.a = "
        <<obj1.aDiff(obj2)<<endl;
    cout<<"Difference b/w value of obj1.b - obj2.b = "
        <<obj1.bDiff(obj2)<<endl;
    return 0;
}

/****************************

Input a b for obj1: 555 13
Input a b for obj2: 12 777
Difference b/w value of obj1.a - obj2.a = 543
Difference b/w value of obj1.b - obj2.b = -764


------------------
(program exited with code: 0)
Press return to continue


******************************/
