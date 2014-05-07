/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Feb 11, 2013
  *     Roll:   UE113090
  *     Program:To concatenate strings using C++
  **/
#include <iostream>
#include <stdio.h>
using namespace std;
const int SIZE=20;
//*****Prototype*****
void gets(char*,int);
void puts(char*,int);
//*****Class Declaration*****
class s1{
    private:
        char var[SIZE];
    public:
        void input(){ gets(var); }
        void display(){ cout<<"\nvar= "; puts(var,SIZE); }
};
class s2{
    private:
        char var[SIZE];
    public:
        void input(){ gets(var); }
        void display(){ cout<<"\nvar= "; puts(var,SIZE); }
};
class s3{
    private:
        char var[1<<SIZE];
    public:
        void input(){ gets(var); }
        void display(){ cout<<"\nvar= "; puts(var,SIZE<<1); }
};
//****************
//******main******
int main(){
    cout<<"Size is: "<<SIZE<<endl;
    cout<<"12345678901234567890\n";
    s1 a;
    s2 b;
    s3 c;
    //Input 
    a.input();
    b.input();
    c.input();
    //Output
    a.display();
    b.display();
    c.display();
    return 0;
}
void gets(char* ptr,int size){
    for(int i=0;i<size;i++){
        ptr[i]=getchar();
    }
}
void puts(char* ptr,int size){
    for(int i=0;i<size;i++){
        cout<<ptr[i]<<'\t';
    }
}
