/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Mar 18, 2013
  *     Roll:       UE113090
  *     Program:    Overload operator '<' and '>'
  **/
#include <iostream>
using namespace std;

class over{
    private:
        int it;
    public:
        void input(int in){ it=in; }
        int output(){ return it; }
        bool operator>(over);
        bool operator<(over in){return (it<in.it)?true:false;}
};
bool over::operator>(over in){
    if(it > in.it){
        return true;
    }
    return false;
}

int main(){
    over a,b;
    a.input(121);
    cout<<"\na it is: "<<a.output();
    b.input(11);
    cout<<"\nb it is: "<<b.output();
    bool result = a > b ;
    cout<<"\na>b returns: "<<result;
    result = a.operator <(b);
    cout<<"\na<b returns: "<< result ;
    return 0;
}
/***************************
a it is: 121
b it is: 11
a>b returns: 1
a<b returns: 0

------------------
(program exited with code: 0)
Press return to continue

****************************/
