/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 22, 2013
  *     Roll:       UE113090
  *     Program:    Make class with virtual function, check object size.
  **/
#include <iostream>
using namespace std;
 
class Base{
   public:    int iv;
    public:
        void daseInput(){
          //  cin>>iv;
        }
        //~ void demo(){
        virtual void demo(){
            //cout<<"\nBase: demo= "<<iv;
        }
};
class Der1 : public Base{
        int i1;
    public:
        void der1Input(){
            //cin>>i1;
        }
        void demo(){
            //cout<<"\nDer1: demo= "<<i1;
        }
};

/*
class Der2 : public Base{
     //   int i2;
    public:
        void der2Input(){
            //cin>>i2;
        }
        void demo(){
            //cout<<"\nDer2: demo= "<<i2;
        }
};
*/
int main(){
    Base objb;
    Der1 obj1;
    //Der2 obj2;
    cout<<"\nSize Base: "<<(sizeof(objb));
    //~ cout<<"sizeof int"<<sizeof(int);
    //cout<<"sizeof class int"<<sizeof(objb.iv);
    
    cout<<"\nSize Der1: "<<(sizeof(obj1));
    //cout<<"\nSize Der2: "<<(sizeof(obj2));

}
/*******************
Without virtual qualifier:
Size Base: 4
Size Der1: 8
Size Der2: 8
With virtual qualifier:
Size Base: 16
Size Der1: 16
Size Der2: 16
********************/
