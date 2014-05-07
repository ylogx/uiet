/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 22, 2013
  *     Roll:       UE113090
  *     Program:    Calculate area, use virtual function
  **/
#include <iostream>
using namespace std;
 
class shape{
    protected:
        //int dim1;
    public:
        //
};
class circle : public shape {
    protected:
        int radius;
    public:
        int area(){
            return ( PI * radius * radius );
        }
};
class square : public shape {
    protected:
        int length, breadth;
    public:
        int area(){
            return ( length * breadth );
        }
};

class
