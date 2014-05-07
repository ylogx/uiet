/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Mar 11, 2013
  *     Roll:   UE113090
  *     Program:Use of Static Function
  **/
#include <iostream>
using namespace std;

class demo{
    private:
        static int varStatic;
    public:
        static void readStatic();
        demo(){     //empty constructor just to show change in static variable
            varStatic++;
        }
};
void demo::readStatic(){
    cout<<"\nvarStatic is: "<<varStatic;
}
int demo::varStatic;
int main(){
    demo a,b,c,d;
    demo::readStatic();
    demo e,f,g,h,i,j;
    demo::readStatic();
    
    return 0;
}
/***********************

varStatic is: 4
varStatic is: 10

------------------
(program exited with code: 0)
Press return to continue

*************************/
